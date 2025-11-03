/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_half.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:04:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 22:33:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	operation_half(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = (*parent_val - 1) / 2;
}

void	center_screen(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	*val = this->parent->_lt.x + (this->parent->size.x / 4) * (render_i + 1 + render_i);
}
