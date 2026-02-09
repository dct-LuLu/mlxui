/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_button_group.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:31:57 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/09 17:17:15 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	precompute_buttons_size(t_hbranch *hbranch)
{
	if (hbranch->button_group.group_dir == GROUP_HORZ)
	{
		hbranch->size.x = get_hbranch_total(
				offsetof(t_hbranch, size.x), hbranch);
		hbranch->size.y = get_hbranch_max(
				offsetof(t_hbranch, size.y), hbranch);
	}
	else
	{
		hbranch->size.x = get_hbranch_max(
				offsetof(t_hbranch, size.x), hbranch);
		hbranch->size.y = get_hbranch_total(
				offsetof(t_hbranch, size.y), hbranch);
	}
}

static inline void	precompute_buttons_pos(t_hbranch *hbranch)
{
	t_hbranch	*child;
	int			pos_offset;
	size_t		i;

	i = 0;
	pos_offset = 0;
	while (i < hbranch->childs->num_elements)
	{
		child = get_hbranch_child_idx(hbranch, i);
		child->anchor = LT;
		child->pos.x = hbranch->_lt.x;
		child->pos.y = hbranch->_lt.y;
		if (hbranch->button_group.group_dir == GROUP_HORZ)
		{
			child->pos.x += pos_offset;
			pos_offset += child->size.x;
		}
		if (hbranch->button_group.group_dir == GROUP_VERT)
		{
			child->pos.y += pos_offset;
			pos_offset += child->size.y;
		}
		i++;
	}
}

static inline void	precompute_buttons_corners(t_hbranch *hbranch)
{
	t_hbranch	*first;
	t_hbranch	*last;

	first = get_hbranch_child_idx(hbranch, 0);
	last = get_hbranch_child_idx(hbranch, hbranch->childs->num_elements - 1);
	first->box.radius = (t_radius){.style = LOCAL_PX, ._mem = 0};
	last->box.radius = (t_radius){.style = LOCAL_PX, ._mem = 0};
	first->box.radius.lt = 5;
	if (hbranch->button_group.group_dir == GROUP_HORZ)
		first->box.radius.lb = 5;
	else
		first->box.radius.rt = 5;
	last->box.radius.rb = 5;
	if (hbranch->button_group.group_dir == GROUP_HORZ)
		last->box.radius.rt = 5;
	else
		last->box.radius.lb = 5;
}

int	precompute_button_group(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*child;

	if (hbranch->childs->num_elements == 0)
		return (0);
	i = 0;
	while (i < hbranch->childs->num_elements)
	{
		child = get_hbranch_child_idx(hbranch, i);
		if (child->type != BUTTON)
			return (1);
		i++;
	}
	precompute_buttons_size(hbranch);
	precompute_geometry(hbranch, 0, 1);
	precompute_buttons_pos(hbranch);
	precompute_buttons_corners(hbranch);
	return (0);
}
