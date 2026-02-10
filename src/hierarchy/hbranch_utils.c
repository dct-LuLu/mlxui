/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbranch_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 05:27:19 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 06:17:53 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

size_t	alloc_slot(t_htree *htree)
{
	size_t	idx;
	size_t	last_pos;

	if (htree->free_slots.num_elements > 0)
	{
		last_pos = htree->free_slots.num_elements - 1;
		idx = *(size_t *)get_vector_value(&htree->free_slots, last_pos);
		htree->free_slots.num_elements--;
		return (idx);
	}
	return (htree->refs.num_elements);
}

void	release_slot(t_htree *htree, size_t idx)
{
	t_hbranch	**slot;

	slot = (t_hbranch **)get_vector_value(&htree->refs, idx);
	*slot = NULL;
	vector_add(&htree->free_slots, &idx, 1);
}
