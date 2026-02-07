/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbranch_iterators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:00:14 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:01:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

int	get_hbranch_max(size_t field_offset, t_hbranch *hbranch)
{
	t_hbranch	*child;
	int			max;
	int			*val;
	size_t		i;

	i = 0;
	max = 0;
	while (i < hbranch->childs->num_elements)
	{
		child = *(t_hbranch **)get_vector_value(hbranch->childs, i);
		val = (int *)((char *)child + field_offset);
		if (*val > max)
			max = *val;
		i++;
	}
	return (max);
}

int	get_hbranch_total(size_t field_offset, t_hbranch *hbranch)
{
	t_hbranch	*child;
	int			total;
	int			*val;
	size_t		i;

	i = 0;
	total = 0;
	while (i < hbranch->childs->num_elements)
	{
		child = *(t_hbranch **)get_vector_value(hbranch->childs, i);
		val = (int *)((char *)child + field_offset);
		total += *val;
		i++;
	}
	return (total);
}
