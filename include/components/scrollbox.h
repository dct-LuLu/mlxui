/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrollbox.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:12:53 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:22:00 by jaubry--         ###   ########.fr       */
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
	uint8_t			sensitivity;
	int				_current_pos;
	t_img_data		_scroll_buffer;
	ssize_t			_event_mwheeldown_idx;
	ssize_t			_event_mwheelup_idx;
	t_hbranch		*inside;
	t_hbranch		*scrollbar;
}					t_scrollbox;

t_hbranch	*add_scrollbox(t_hbranch *parent_branch);
void		destroy_scrollbox(t_hbranch *scrollbox);
int			precompute_scrollbox(t_hbranch *hbranch);
void		render_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox);
void		render_clear_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox);

#endif//SCROLLBOX_H
