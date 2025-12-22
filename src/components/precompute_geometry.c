/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_geometry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:28:03 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 00:23:39 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"
#include <stddef.h>

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

void	precompute_geometry(t_hbranch *this, size_t render_i, size_t render_num)
{
	if (this->x_size_operation)
		this->x_size_operation(offsetof(t_hbranch, size.x), this, render_i, render_num);
	if (this->y_size_operation)
		this->y_size_operation(offsetof(t_hbranch, size.y), this, render_i, render_num);
	if (this->x_pos_operation)
		this->x_pos_operation(offsetof(t_hbranch, pos.x), this, render_i, render_num);
	if (this->y_pos_operation)
		this->y_pos_operation(offsetof(t_hbranch, pos.y), this, render_i, render_num);
	this->_lt = get_anchor_pos(this->anchor, this->pos, this->size);
	this->_rb = vec2i_add(this->_lt, this->size);
	this->_rt = vec2i(this->_rb.x, this->_lt.y);
	this->_lb = vec2i(this->_lt.x, this->_rb.y);
	this->_half_size = vec2_scale(vec2_itof(this->size), 0.5);
	this->_mid = vec2i(this->_lt.x + roundf(this->_half_size.x),
			this->_lt.y + roundf(this->_half_size.y));
}
