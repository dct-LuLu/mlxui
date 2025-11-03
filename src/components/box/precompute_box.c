/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:13:07 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 20:18:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	precompute_box(t_hbranch *hbranch)
{
	//if (box->radius._mem > 100)
	//	printf("error\n");
	/*
	if (((box->pos.x < 0) || (box->pos.y < 0))
		|| ((box->pos.x > WIDTH) || (box->pos.y > HEIGHT)))
		return (0);
	else if ((box->size.x < 0) || (box->size.y < 0))
		printf("error\n");
	*/
	hbranch->box._ltc.corner = hbranch->_lt;
	hbranch->box._rbc.corner = hbranch->_rb;
	hbranch->box._rtc.corner = hbranch->_rt;
	hbranch->box._lbc.corner = hbranch->_lb;
	if (hbranch->box.radius.style != NO_RADIUS)
		precompute_box_radius(&(hbranch->box));
	//return (0);
}
