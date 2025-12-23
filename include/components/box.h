/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:34:58 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:35:59 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

# include "mlx_wrapper.h"
# include "geometry_fields.h"

typedef enum e_border_style
{
	NO_BORDER = 0,
	SOLID,
	DASHED
}	t_border_style;

typedef struct s_border
{
	uint8_t			size;
	t_rgba_int		color;
	t_border_style	style;
}					t_border;

typedef enum e_radius_style
{
	NO_RADIUS = 0,
	FULL_PERCENT,
	FULL_PX,
	LOCAL_PERCENT,
	LOCAL_PX
}	t_radius_style;

typedef struct s_radius
{
	t_radius_style	style;
	union
	{
		uint32_t	_mem;
		struct
		{
			uint8_t	lt;
			uint8_t	rt;
			uint8_t	lb;
			uint8_t	rb;
		};
		uint8_t		full;
	};
}					t_radius;

typedef struct s_corner
{
	union
	{
		struct
		{
			t_vec2i	horz;
			t_vec2i	corner;
			t_vec2i	vert;
			t_vec2i	in;
		};
		t_vec2i		_mem[4];
		t_vec2i		_mem3[3];
	};
	t_vec2i			xrec[2];
	t_vec2i			mrec[2];
}					t_corner;

typedef struct s_box
{
	struct __attribute__((packed))
	{
		t_anchor	anchor;
		struct
		{
			t_vec2i	pos;
			void	(*x_pos_operation)(size_t, t_hbranch *, size_t, size_t);
			void	(*y_pos_operation)(size_t, t_hbranch *, size_t, size_t);
		};
		struct
		{
			t_vec2i	size;
			void	(*x_size_operation)(size_t, t_hbranch *, size_t, size_t);
			void	(*y_size_operation)(size_t, t_hbranch *, size_t, size_t);
		};
		void		(*precompute)(t_hbranch *);
		void		(*render)(t_hbranch *, void *);
		t_vec2		_half_size;
		t_vec2i		_mid;
		t_vec2i		_lt;
		t_vec2i		_rt;
		t_vec2i		_lb;
		t_vec2i		_rb;
		t_img_data	*img;
		t_hbranch	*_in_scrollbox;
	};
	t_rgba_int	color;
	t_radius	radius;
	t_border	border;
	t_corner	_ltc;
	t_corner	_rtc;
	t_corner	_lbc;
	t_corner	_rbc;
}				t_box;

t_hbranch	*add_box(t_hbranch *parent_branch,
				t_radius radius, t_border border);
void		precompute_box(t_hbranch *hbranch);
void		render_box(t_hbranch *hbranch, t_box *box);
void		precompute_box_radius(t_box *box);
void		render_border(t_img_data *img, t_box box);

#endif//BOX_H
