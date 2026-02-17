/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorpicker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:32:38 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/17 09:26:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORPICKER_H
# define COLORPICKER_H

# define CPICKER_KNOB_RADIUS 6
# define CPICKER_CIRCLE_RADIUS 90
# define CPICKER_POPUP_SIZE 200

typedef struct s_colorpicker
{
	union
	{
		struct __attribute__((packed))
		{
			t_anchor		anchor;
			struct
			{
				t_vec2i		pos;
				void		(*x_pos_operation)(size_t, t_hbranch *, size_t, size_t);
				void		(*y_pos_operation)(size_t, t_hbranch *, size_t, size_t);
			};
			struct
			{
				t_vec2i		size;
				void		(*x_size_operation)(size_t, t_hbranch *, size_t, size_t);
				void		(*y_size_operation)(size_t, t_hbranch *, size_t, size_t);
			};
			int				(*precompute)(t_hbranch *);
			void			(*render)(t_hbranch *, void *);
			t_vec2			_half_size;
			t_vec2i			_mid;
			t_vec2i			_lt;
			t_vec2i			_rt;
			t_vec2i			_lb;
			t_vec2i			_rb;
			t_img_data		*img;
			t_hbranch		*_in_scrollbox;
		};
		t_box				box;
	};
	t_rgb				rgb;
	bool				popup_open;
	bool				_dragging;
	t_vec2i				_circle_center;
	t_vec2i				_knob_pos;
	t_hbranch			*popup;
	void				(*_hook_click)(t_vec2i, t_maction, void *, t_mlx *);
	void				(*_hook_hover)(void *, t_mlx *);
	union
	{
		struct
		{
			void		(*action)(t_hbranch *hbranch, void *arg);
			void		*arg;
		};
		struct
		{
			void		(*action2)(t_hbranch *hbranch, void *arg1, void *arg2);
			void		*args2[2];
		};
		struct
		{
			void		(*action3)(t_hbranch *hbranch, void *arg1, void *arg2, void *arg3);
			void		*args3[3];
		};
	};
}	t_colorpicker;

t_hbranch	*add_colorpicker(t_hbranch *parent_branch, t_rgb rgb);
void		destroy_colorpicker(t_hbranch *colorpicker);
int			precompute_colorpicker(t_hbranch *hbranch);
void		render_colorpicker_preview(t_hbranch *hbranch, t_colorpicker *colorpicker);
void		render_colorpicker_popup(t_hbranch *hbranch, t_colorpicker *colorpicker);
void		hook_click_colorpicker(t_vec2i pos, t_maction action,
				t_hbranch *hbranch, t_mlx *mlx_data);
void		hook_hover_colorpicker(t_hbranch *hbranch, t_mlx *mlx_data);
void		compute_colorpicker_knob_position(t_hbranch *hbranch);
t_rgb		hsv_to_rgb(float h, float s, float v);
void		rgb_to_hsv(t_rgb rgb, float *h, float *s, float *v);

#endif//COLORPICKER_H
