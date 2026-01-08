/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_scrollbox.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:46:16 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:18:17 by jaubry--         ###   ########.fr       */
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

void	precompute_scrollbox(t_hbranch *hbranch)
{
	int	height;

	if (false)
		height = get_childs_height(hbranch);
	else
		height = hbranch->scrollbox.inside->size.y;
	hbranch->scrollbox._scroll_buffer.height = height;
	hbranch->scrollbox._scroll_buffer.width
		= hbranch->scrollbox.inside->size.x;
	hbranch->scrollbox._scroll_buffer.channels = 4;
	hbranch->scrollbox._scroll_buffer.line_len
		= hbranch->scrollbox.inside->size.x * 4;
	hbranch->scrollbox._scroll_buffer.pixels
		= malloc(height * hbranch->scrollbox.inside->size.x * 4);
	if (!hbranch->scrollbox._scroll_buffer.pixels)
		printf("error malloc\n");
	precompute_scrollbar(hbranch);
}
