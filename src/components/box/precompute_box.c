/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:13:07 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/30 18:51:44 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static inline t_vec2i	get_anchor_pos(t_anchor anchor, t_vec2i pos, t_vec2i size)
{
	t_vec2i	real_pos;

	if ((anchor == CENTER) || (anchor == TOP) || (anchor == BOTTOM))
		real_pos.x = pos.x - (size.x / 2);
	if ((anchor == CENTER) || (anchor == LEFT) || (anchor == RIGHT))
		real_pos.y = pos.y - (size.y / 2);
	if ((anchor == LEFT) || (anchor == LT) || (anchor == LB))
		real_pos.x = pos.x;
	if ((anchor == RIGHT) || (anchor == RT) || (anchor == RB))
		real_pos.x = pos.x - size.x;
	if ((anchor == TOP) || (anchor == LT) || (anchor == RT))
		real_pos.y = pos.y;
	if ((anchor == BOTTOM) || (anchor == LB) || (anchor == RB))
		real_pos.y = pos.y - size.y;
	return (real_pos);
}

int	precompute_box(t_box *box)
{
	//if (box->radius._mem > 100)
	//	printf("error\n");
	if (((box->pos.x < 0) || (box->pos.y < 0))
		|| ((box->pos.x > WIDTH) || (box->pos.y > HEIGHT)))
		return (0);
	else if ((box->size.x < 0) || (box->size.y < 0))
		printf("error\n");
	box->_ltc.corner = get_anchor_pos(box->anchor, box->pos, box->size);
	box->_rbc.corner = vec2i_add(box->_ltc.corner, box->size);
	box->_rtc.corner = vec2i(box->_rbc.corner.x, box->_ltc.corner.y);
	box->_lbc.corner = vec2i(box->_ltc.corner.x, box->_rbc.corner.y);
	box->_half_size = vec2_scale(vec2_itof(box->size), 0.5);
	if (box->radius.style != NO_RADIUS)
		precompute_box_radius(box);
	return (0);
}
