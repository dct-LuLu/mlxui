/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_scrollbox.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:46:16 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 00:22:16 by jaubry--         ###   ########.fr       */
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

void	precompute_hbranch(t_hbranch *hbranch);

void	precompute_scrollbox(t_hbranch *hbranch)
{
	int	height;

	//precompute_hbranch(hbranch);
	if (false)
		height = get_childs_height(hbranch);
	else
		height = hbranch->scrollbox.inside->size.y;
	//hbranch->scrollbox.inside->_offset = hbranch->_lt;
	//precompute_geometry(hbranch->scrollbox.inside, 0, 1);
	//printf("ofset: %d %d\n", hbranch->scrollbox.inside->_offset.x, hbranch->scrollbox.inside->_offset.y);
	//printf("%d %d\n", hbranch->pos.x, hbranch->pos.y);
	//hbranch->scrollbox.inside->size = vec2i(hbranch->size.x, height);
	hbranch->scrollbox._scroll_buffer.height = height;
	hbranch->scrollbox._scroll_buffer.width = hbranch->scrollbox.inside->size.x;
	hbranch->scrollbox._scroll_buffer.channels = 4;
	hbranch->scrollbox._scroll_buffer.line_len = hbranch->scrollbox.inside->size.x * 4;
	hbranch->scrollbox._scroll_buffer.pixels = malloc(height * hbranch->scrollbox.inside->size.x * 4);
	if (!hbranch->scrollbox._scroll_buffer.pixels)
		printf("error malloc\n");
}
