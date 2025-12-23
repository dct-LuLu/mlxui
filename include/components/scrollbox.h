/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrollbox.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:12:53 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:36:36 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCROLLBOX_H
# define SCROLLBOX_H

typedef struct s_scrollbox
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
	t_hbranch		*inside;
	t_hbranch		*scrollbar;
	uint8_t			sensitivity;
	int				_current_pos;
	t_img_data		_scroll_buffer;
}					t_scrollbox;

t_hbranch	*add_scrollbox(t_hbranch *parent_branch);
void		precompute_scrollbox(t_hbranch *hbranch);
void		render_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox);
void		render_clear_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox);

#endif//SCROLLBOX_H
