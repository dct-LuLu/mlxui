/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:07:04 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/28 19:42:42 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# define SELECT_LABEL_LEN 20

# define MAX_OPTIONS 5

/*
	selected:
		component for text always displayed
	
	options:
		button childs of margin
*/
typedef struct s_select
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
		t_button		button;
	};
	t_textbox			*selected;
	bool				expanded;
	size_t				option_index;
	t_hbranch			*label_box;
	t_hbranch			*expand;
	t_hbranch			*margin;
	t_vector			*options;
	t_vector			*actions;
	bool				nullable;
}						t_select;

typedef void	(*t_option_action)(t_hbranch *hbranch, void *arg);

t_hbranch	*add_select(t_hbranch *parent_branch, char label[SELECT_LABEL_LEN]);
void		render_select(t_hbranch *hbranch, t_select *select);
void		render_select_overlay(t_hbranch *hbranch, t_select *select);
int			add_select_option(t_hbranch *select,
				char option_name[SELECT_LABEL_LEN],
				void (*option_action)(t_hbranch *hbranch, void *arg));

#endif//SELECT_H
