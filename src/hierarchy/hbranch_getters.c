/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbranch_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 06:17:58 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 06:18:00 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Return the component associated with idx inside htree->refs
*/
t_hbranch   *ref_at(t_htree *htree, size_t idx)
{
    return (*(t_hbranch **)get_vector_value(&htree->refs, idx));
}

/*
	Reads the index stored in the childs vector, and uses it to get the component in
	htree->refs
*/
t_hbranch   *get_hbranch_child_idx(t_hbranch *parent, size_t idx)
{
	size_t		ref_idx;

	ref_idx = *(size_t *)get_vector_value(parent->childs, idx);
	return (ref_at(parent->head, ref_idx));
}

/*
	Returns the found index value in child, if comp not found, return -1
*/
ssize_t	get_hbranch_index(t_vector *v, t_hbranch *hbranch)
{
	size_t	i;
	size_t	*refs_idx;

	if (!v || !hbranch)
		return (-1);
	i = 0;
	refs_idx = v->data;
	while (i < v->num_elements)
	{
		if (hbranch == ref_at(hbranch->head, refs_idx[i]))
			return (i);
		i++;
	}
	return (-1);
}
