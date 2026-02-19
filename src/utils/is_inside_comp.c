/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_comp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:55:43 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 17:44:56 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

t_vec2i	get_absolute_pos(t_hbranch *hbranch, t_vec2i pos)
{
	t_vec2i	realpos;

	if (hbranch->_in_scrollbox && is_inside_comp(hbranch->_in_scrollbox, pos))
	{
		realpos = vec2i_sub(pos, hbranch->_in_scrollbox->_lt);
		realpos.y += hbranch->_in_scrollbox->scrollbox._current_pos;
	}
	else
		realpos = pos;
	return (realpos);
}

/*
	Will determine if in a scrollbox and then adjust to realpos click
*/
bool	is_inside_comp(t_hbranch *hbranch, t_vec2i pos)
{
	const t_vec2i	realpos = get_absolute_pos(hbranch, pos);

	if (hbranch->_in_scrollbox && !is_inside_comp(hbranch->_in_scrollbox, pos))
		return (false);
	return ((realpos.x > hbranch->_lt.x) && (realpos.x < hbranch->_rt.x)
		&& (realpos.y > hbranch->_lt.y) && (realpos.y < hbranch->_rb.y));
}
