/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrollbox.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:12:53 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/21 23:00:55 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCROLLBOX_H
# define SCROLLBOX_H

typedef struct s_scrollbox
{
	ANON_GEOM_PACKED;
	t_hbranch	*inside;
	uint16_t	_current_pos;// 0 de base
	t_img_data	_scroll_buffer;
}	t_scrollbox;

// uniquement y axis

// draw t_img_data.pixels[_current_pos * img_data.line_len] jusqu'a scrollbox.height
// edit .img of t_branch at creation
//
// use special render to render after all was already drawn to it
//
// precompute will allocate and determine height of the scroll_buffer

t_hbranch	*add_scrollbox(t_hbranch *parent_branch);
void		precompute_scrollbox(t_hbranch *hbranch);
void		render_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox);
void	render_clear_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox);

#endif//SCROLLBOX_H
