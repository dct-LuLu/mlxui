/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 09:45:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/06 12:16:33 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	selected_offset_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = *parent_val + 10;
}

void	margin_offset_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = *parent_val + 2;
}

void	expanded_offset(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = *parent_val + 42;
}

void	entry_offset(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = *parent_val + 36;
}
/*
void	option_offset_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = *parent_val + 8;
}
*/
