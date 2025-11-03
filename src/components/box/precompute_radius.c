/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_radius.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:15:49 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 21:17:07 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

#define LT 0
#define RT 1
#define LB 2
#define RB 3

static inline void	set_box_corner(t_corner *data, t_vec2 size, int val)
{
	if ((val == LT) || (val == LB))
		data->horz = vec2i(data->corner.x + size.x, data->corner.y);
	else if ((val == RT) || (val == RB))
		data->horz = vec2i(data->corner.x - size.x, data->corner.y);
	if ((val == LT) || (val == RT))
		data->vert = vec2i(data->corner.x, data->corner.y + size.y);
	else if ((val == LB) || (val == RB))
		data->vert = vec2i(data->corner.x, data->corner.y - size.y);
	data->in = vec2i(data->horz.x, data->vert.y);
}

static inline void	precompute_corner_radius(t_box *box)
{
	const t_vec2	size = vec2_itof(box->size);
	t_vec2			corners_size[4];

	if ((box->radius.style == FULL_PERCENT) || (box->radius.style == LOCAL_PERCENT))
	{
		corners_size[LT] = vec2_scale(size, (float)box->radius.lt / 200.0f);	
		corners_size[RT] = vec2_scale(size, (float)box->radius.rt / 200.0f);	
		corners_size[LB] = vec2_scale(size, (float)box->radius.lb / 200.0f);	
		corners_size[RB] = vec2_scale(size, (float)box->radius.rb / 200.0f);	
	}
	else if ((box->radius.style == FULL_PX) || (box->radius.style == LOCAL_PX))
	{
		corners_size[LT] = vec2_min(vec2(box->radius.lt, box->radius.lt), box->_half_size);
		corners_size[RT] = vec2_min(vec2(box->radius.rt, box->radius.rt), box->_half_size);
		corners_size[LB] = vec2_min(vec2(box->radius.lb, box->radius.lb), box->_half_size);
		corners_size[RB] = vec2_min(vec2(box->radius.rb, box->radius.rb), box->_half_size);
	}
	else
		return ;
	set_box_corner(&box->_ltc, corners_size[LT], LT);
	set_box_corner(&box->_rtc, corners_size[RT], RT);
	set_box_corner(&box->_lbc, corners_size[LB], LB);
	set_box_corner(&box->_rbc, corners_size[RB], RB);
}

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
