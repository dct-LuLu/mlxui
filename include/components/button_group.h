/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_group.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:32:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:36:10 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_GROUP_H
# define BUTTON_GROUP_H

typedef enum e_group_dir
{
	GROUP_HORZ,
	GROUP_VERT
}	t_group_dir;

typedef enum e_group_type
{
	GROUP_DEFAULT,
	GROUP_SWITCH
}	t_group_type;

typedef struct s_button_group
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
	t_group_dir		group_dir;
	t_group_type	group_type;
	size_t			switched_index;
}					t_button_group;

t_hbranch	*add_button_group(t_hbranch *parent_branch,
				t_group_dir group_dir, t_group_type group_type);
void		render_button_group_overlay(t_hbranch *hbranch);
void		precompute_button_group(t_hbranch *hbranch);

#endif//BUTTON_GROUP_H
