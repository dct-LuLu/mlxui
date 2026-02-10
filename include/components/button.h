/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:51:51 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:22:00 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

typedef struct s_button
{
	union
	{
		struct __attribute__((packed))
		{
			t_anchor	anchor;
			struct
			{
				t_vec2i	pos;
				void	(*x_pos_operation)(size_t, t_hbranch *,
						size_t, size_t);
				void	(*y_pos_operation)(size_t, t_hbranch *,
						size_t, size_t);
			};
			struct
			{
				t_vec2i	size;
				void	(*x_size_operation)(size_t, t_hbranch *,
						size_t, size_t);
				void	(*y_size_operation)(size_t, t_hbranch *,
						size_t, size_t);
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
		t_box			box;
	};
	bool				hover;
	void				*arg;
	void				(*action)(t_hbranch *hbranch, void *arg);
	void				(*_hook_click)(t_vec2i, t_maction, void*, t_mlx*);
	void				(*_hook_hover)(void*, t_mlx*);
}						t_button;

t_hbranch	*add_button(t_hbranch *parent_branch,
				t_radius radius, t_border border);
void		destroy_button(t_hbranch *button);
void		render_button_overlay(t_hbranch *hbranch);
void		hook_click_button(t_vec2i pos, t_maction action,
				t_hbranch *hbranch, t_mlx *mlx_data);
void		hook_hover_button(t_hbranch *hbranch, t_mlx *mlx_data);

#endif//BUTTON_H
