/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_scrollbox.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:46:16 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/06 06:12:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline int	get_childs_height(t_hbranch *hbranch)
{
	t_hbranch	*cur;
	size_t		i;
	int			total;

	total = 0;
	i = 0;
	while (i < hbranch->childs->num_elements)
	{
		cur = get_vector_value(hbranch->childs, i);
		if (cur->visible && (cur->_lb.y > total))
			total = cur->_lb.y;
		i++;
	}
	return (total);
}

void	precompute_scrollbar(t_hbranch *hbranch)
{
	t_hbranch	*scrollbar;

	scrollbar = hbranch->scrollbox.scrollbar;
	if (hbranch->size.y >= hbranch->scrollbox.inside->size.y)
		scrollbar->size.y = hbranch->size.y;
	else
	{
		scrollbar->size.y = ((float)hbranch->size.y
				/ (float)hbranch->scrollbox.inside->size.y)
			* (float)hbranch->size.y;
	}
	scrollbar->pos.x = hbranch->_rt.x;
	scrollbar->pos.y = hbranch->_rt.y
		+ ((float)hbranch->scrollbox._current_pos
			/ (float)hbranch->scrollbox.inside->size.y)
		* (float)hbranch->size.y;
}

int	precompute_scrollbox(t_hbranch *hbranch)
{
	t_img_data	*scroll_buf;

	scroll_buf = &hbranch->scrollbox._scroll_buffer;
	if (false)
		scroll_buf->height = get_childs_height(hbranch);
	else
		scroll_buf->height = hbranch->scrollbox.inside->size.y;
	scroll_buf->width = hbranch->scrollbox.inside->size.x;
	scroll_buf->channels = 4;
	scroll_buf->line_len = scroll_buf->width * scroll_buf->channels;
	scroll_buf->pixels = ft_calloc(scroll_buf->height * scroll_buf->line_len, sizeof(uint8_t));
	if (!scroll_buf->pixels)
		return (1);
	precompute_scrollbar(hbranch);
	return (0);
}
