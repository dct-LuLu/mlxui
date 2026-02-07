/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_comp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:55:43 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/07 00:14:50 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

/*
	Will determine if in a scrollbox and then adjust to realpos click
*/
bool	is_inside_comp(t_hbranch *hbranch, t_vec2i pos)
{
	t_vec2i	realpos;

	if (hbranch->_in_scrollbox)
	{
		if (!is_inside_comp(hbranch->_in_scrollbox, pos))
			return (false);
		realpos = vec2i_sub(pos, hbranch->_in_scrollbox->_lt);
		realpos.y += hbranch->_in_scrollbox->scrollbox._current_pos;
	}
	else
		realpos = pos;
	return ((realpos.x > hbranch->_lt.x) && (realpos.x < hbranch->_rt.x)
		&& (realpos.y > hbranch->_lt.y) && (realpos.y < hbranch->_rb.y));
}
