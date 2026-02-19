/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:57:53 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:01:18 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLIDER_H
# define SLIDER_H

# define SLIDER_BUF_SIZE 20
# define SLIDER_KNOB_RADIUS 6
# define SLIDER_BAR_HEIGHT 4
# define SLIDER_BAR_OFFSET 30
# define SLIDER_TEXT_OFFSET 8

typedef struct s_slider
{
	struct
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
		int			(*precompute)(t_hbranch *);
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
	bool			linear_step;
	bool			_dragging;
	int				_bar_width;
	t_vec2i			_bar_start;
	t_vec2i			_bar_end;
	t_vec2i			_knob_pos;
	ssize_t			_event_click_idx;
	ssize_t			_event_move_idx;
	float			start;
	float			stop;
	float			step;
	float			value;
	float			*ptr;
	t_hbranch		*start_text;
	t_hbranch		*end_text;
	union
	{
		struct
		{
			t_action	*action;
			void		*arg;
		};
		struct
		{
			t_action2	*action2;
			void		*args2[2];
		};
		struct
		{
			t_action3	*action3;
			void		*args3[3];
		};
	};
}	t_slider;

t_hbranch	*add_slider(t_hbranch *parent_branch, float *ptr, float start,
				float stop);
void		destroy_slider(t_hbranch *slider);
void		compute_slider_knob_position(t_hbranch *hbranch);
int			precompute_slider(t_hbranch *hbranch);
void		render_slider(t_hbranch *hbranch, t_slider *slider);
void		hook_drag_slider(t_vec2i pos, t_maction action,
				t_hbranch *hbranch, t_mlx *mlx_data);
void		hook_hover_slider(t_hbranch *hbranch, t_mlx *mlx_data);

float		value_to_ratio_linear(t_slider *slider, float value);
float		ratio_to_value_linear(t_slider *slider, float ratio);
float		value_to_ratio_log(t_slider *slider, float value);
float		ratio_to_value_log(t_slider *slider, float ratio);

#endif//SLIDER_H
