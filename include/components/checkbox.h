/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:25 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/09 16:59:12 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKBOX_H
# define CHECKBOX_H

# include "box.h"

typedef struct s_checkbox
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
	bool				*checked;
}						t_checkbox;

t_hbranch	*add_checkbox(t_hbranch *parent_branch, bool *checked);
int			precompute_checkbox(t_hbranch *hbranch);
void		render_checkbox(t_hbranch *hbranch, t_checkbox *checkbox);
void		switch_checkbox(t_hbranch *checkbox);
void		hook_checkbox(t_vec2i pos, t_maction action,
				t_hbranch *hbranch, t_mlx *mlx_data);

#endif//CHECKBOX_H
