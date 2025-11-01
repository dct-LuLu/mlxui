/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_geometry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:28:03 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/01 17:37:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

int	get_total_branches_size_x(t_hbranch *parent)
{
	size_t	i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < parent->branches->num_elements)
		sum += get_vector_value(parent->branches, i++)->rsize.x;
	return (sum);
}

/*
	Simple span x implementation doesnt taje into account min and max values
*/
int	operation_inherit_span_size_x(t_hbranch *this)
{
	return (this->parent->size.x / this->parent->branches->num_elements);
}

static inline void	precompute_pos(t_hbranch *this, struct s_rpos *rpos)
{
	size_t	i;
	int		sum;

	if (rpos->x.type == INHERIT)
		*(rpos->x.val) = rpos->x.operation(this->parent->rpos.x);
	else if (rpos->x.type == ADAPT)
	{
		i = 0;
		sum = 0;
		while (i < current_branch->branches->num_elements)
			sum += get_vector_value(this->branches, i++)->rpos.x;
		*(rpos->x.val) = rpos->x.operation(sum);
	}
	if (rpos->y.type == INHERIT)
		*(rpos->y.val) = rpos->y.operation(this->parent->rpos.y);
	else if (rpos->y.type == ADAPT)
	{
		i = 0;
		sum = 0;
		while (i < current_branch->branches->num_elements)
			sum += get_vector_value(this->branches, i++)->rpos.y;
		*(rpos->y.val) = rpos->y.operation(sum);
	}
}

static inline void	precompute_size(t_hbranch *this, struct s_rsize *rsize)
{
	size_t	i;
	int		sum;

	if (rsize->x.type == INHERIT)
		*(rsize->x.val) = rsize->x.operation(this->parent->rsize.x);
	else if (rsize->x.type == ADAPT)
	{
		i = 0;
		sum = 0;
		while (i < current_branch->branches->num_elements)
			sum += get_vector_value(this->branches, i++)->rsize.x;
		*(rsize->x.val) = rsize->x.operation(sum);
	}
	if (rsize->y.type == INHERIT)
		*(rsize->y.val) = rsize->y.operation(this->parent->rsize.y);
	else if (rsize->y.type == ADAPT)
	{
		i = 0;
		sum = 0;
		while (i < current_branch->branches->num_elements)
sum += get_vector_value(this->branches, i++)->rsize.y;
		*(rsize->y.val) = rsize->y.operation(sum);
	}
}

void	precompute_geometry(t_hbranch *this)
{
	if (this->parent == NULL)
		return ;
	precompute_pos(this, &this->rpos);
	precompute_size(this, &this->rsize);
}



/*
if (ABSOLUTE) // SIZE & POS
	set PX
	compute PERCENTAGE
	use OPERATION

else if (ADAPT) // only for SIZE
	use OPERATION

else if (INHERIT)
	set PX //only for POS
	compute PERCENTAGE// POS & SIZE
	use OPERATION// all
*/


int	get_field_sum(size_t field_offset, t_hbranch *parent)
{
	size_t	i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < parent->branches->num_elements)
		sum += *((int *)((char *)get_vector_value(parent->branches, i++) + field_offset));
	return (sum);
}

void	operation_half(size_t field_offset, t_hbranch *this, void *arg)
{
	int	*res;
	int	*parent;

	(void)arg;
	res = (int *)((char *)this + field_offset);
	parent = (int *)((char *)this->parent + field_offset);
	*res = *parent / 2;
}

void	precompute_geometry(t_hbranch *this)
{
	this->rpos.x.operation(offsetof(t_geometry, this->pos.x), this, this->rpos.x.arg);
	this->rpos.y.operation(offsetof(t_geometry, this->pos.y), this, this->rpos.y.arg);
	this->rsize.x.operation(offsetof(t_geometry, this->size.x), this, this->rsize.x.arg);
	this->rsize.y.operation(offsetof(t_geometry, this->size.y), this, this->rsize.y.arg);
}
