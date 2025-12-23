/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_radius.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:15:49 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:51:24 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	precompute_corner_radius(t_box *box);

static inline void	precompute_xrec(t_box *box, t_corner *corner)
{
	corner->xrec[0] = vec2i(
			min(corner->in.x, box->_mid.x) + 1,
			min(corner->in.y, corner->corner.y)
			);
	corner->xrec[1] = vec2i(
			max(corner->in.x - 1, box->_mid.x),
			max(corner->in.y, corner->corner.y)
			);
}

static inline void	precompute_mrec(t_box *box, t_corner *corner)
{
	corner->mrec[0] = vec2i(
			min(corner->vert.x, box->_mid.x + 1),
			min(corner->vert.y, box->_mid.y) + 1
			);
	corner->mrec[1] = vec2i(
			max(corner->vert.x, box->_mid.x),
			max(corner->vert.y - 1, box->_mid.y)
			);
}

static inline void	precompute_in_rec(t_box *box)
{
	precompute_xrec(box, &box->_ltc);
	precompute_xrec(box, &box->_rtc);
	precompute_xrec(box, &box->_lbc);
	precompute_xrec(box, &box->_rbc);
	precompute_mrec(box, &box->_ltc);
	precompute_mrec(box, &box->_rtc);
	precompute_mrec(box, &box->_lbc);
	precompute_mrec(box, &box->_rbc);
}

void	precompute_box_radius(t_box *box)
{
	if ((box->radius.style == FULL_PERCENT) || (box->radius.style == FULL_PX))
	{
		box->radius.lt = box->radius.full;
		box->radius.rt = box->radius.full;
		box->radius.lb = box->radius.full;
		box->radius.rb = box->radius.full;
	}
	precompute_corner_radius(box);
	precompute_in_rec(box);
}
