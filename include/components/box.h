/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:34:58 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/30 18:39:01 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

typedef enum e_border_style
{
	NO_BORDER = 0,
	SOLID,
	DASHED
}	t_border_style;

typedef struct s_border
{
	uint8_t			size;// px
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
		uint8_t	full;
	};
}	t_radius;

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
	t_vec2i	xrec[2];
	t_vec2i	mrec[2];
}	t_corner;

typedef struct s_box
{
	t_geometry;
	t_rgba_int	color;
	t_radius	radius;
	t_border	border;
	t_corner	_ltc;
	t_corner	_rtc;
	t_corner	_lbc;
	t_corner	_rbc;
}				t_box;

void	precompute_box_radius(t_box *box);
int		precompute_box(t_box *box);
void	draw_border(t_img_data *img, t_box box);
void	draw_box(t_img_data *img, t_box box);

#endif//BOX_H
