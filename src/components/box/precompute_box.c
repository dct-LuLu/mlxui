/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:13:07 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/09 16:57:08 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

int	precompute_box(t_hbranch *hbranch)
{
	hbranch->box._ltc.corner = hbranch->_lt;
	hbranch->box._rbc.corner = hbranch->_rb;
	hbranch->box._rtc.corner = hbranch->_rt;
	hbranch->box._lbc.corner = hbranch->_lb;
	if (hbranch->box.radius.style != NO_RADIUS)
		precompute_box_radius(&(hbranch->box));
	return (0);
}
