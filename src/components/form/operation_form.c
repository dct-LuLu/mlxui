/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:32:17 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/25 23:39:06 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	center_abs_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	if (val == &this->pos.x)
		*val = this->parent->_mid.x;
	else if (val == &this->pos.y)
		*val = this->parent->_mid.y + 8;
}

void	copy_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	int	*val;
	int	*parent_val;

	(void)render_i;
	(void)render_num;
	val = (int *)((char *)this + field_offset);
	parent_val = (int *)((char *)this->parent + field_offset);
	*val = *parent_val;
}

void	form_suffix_pos_x(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	t_hbranch	*buf;

	(void)field_offset;
	if (render_i != 1 || render_num != 2)
		return ;
	buf = (t_hbranch *)get_vector_value(this->parent->childs, 0);
	this->pos.x = buf->_mid.x + (measure_str_width(buf->textbox.text.content, &buf->textbox.text) / 2) + 5;
}

void	form_suffix_size_x(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num)
{
	t_hbranch	*buf;

	(void)field_offset;
	if ((render_i != 1) || (render_num != 2))
		return ;
	buf = (t_hbranch *)get_vector_value(this->parent->childs, 0);
	this->size.x = this->parent->_rt.x - buf->_rt.x;
}
