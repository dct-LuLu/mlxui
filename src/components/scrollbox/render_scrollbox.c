/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scrollbox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:45:37 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:19:09 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_clear_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox)
{
	(void)hbranch;
	ft_bzero(scrollbox->_scroll_buffer.pixels,
		scrollbox->_scroll_buffer.channels * scrollbox->_scroll_buffer.height
		* scrollbox->_scroll_buffer.width);
}

void	render_scrollbox(t_hbranch *hbranch, t_scrollbox *scrollbox)
{
	uint8_t	*save_ptr;
	ssize_t	save_height;

	save_ptr = scrollbox->_scroll_buffer.pixels;
	scrollbox->_scroll_buffer.pixels = &scrollbox->_scroll_buffer.pixels
	[scrollbox->_current_pos * scrollbox->_scroll_buffer.line_len];
	save_height = scrollbox->_scroll_buffer.height;
	if (hbranch->size.y >= scrollbox->inside->size.y)
		scrollbox->_scroll_buffer.height = scrollbox->inside->size.y;
	else
	scrollbox->_scroll_buffer.height = hbranch->size.y;
	ft_mlx_img_aput(hbranch->img, hbranch->_lt, &scrollbox->_scroll_buffer);
	scrollbox->_scroll_buffer.height = save_height;
	scrollbox->_scroll_buffer.pixels = save_ptr;
	render_box(scrollbox->scrollbar, &scrollbox->scrollbar->box);
}
