/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hierarchy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:56:06 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/20 15:53:35 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	free_node_recursive(t_hbranch *hbranch);

static inline void	unlink_from_parent(t_hbranch *hbranch)
{
	size_t		i;
	size_t		*child_idx;
	t_hbranch	*candidate;

	i = 0;
	while (i < hbranch->parent->childs->num_elements)
	{
		candidate = get_hbranch_child_idx(hbranch->parent, i);
		if (candidate == hbranch)
		{
			child_idx = (size_t *)get_vector_value(hbranch->parent->childs, i);
			release_slot(hbranch->parent->head, *child_idx);
			remove_vector_elem(hbranch->parent->childs, i);
			return ;
		}
		i++;
	}
}

void	delete_node_childs(t_hbranch *parent)
{
	size_t		i;
	t_hbranch	*child;

	if (!parent || !parent->childs || !parent->childs->data)
		return ;
	i = 0;
	while (i < parent->childs->num_elements)
	{
		child = get_hbranch_child_idx(parent, i);
		if (child)
			free_node_recursive(child);
		i++;
	}
	free_vector(parent->childs);
	vector_init(parent->childs, sizeof(size_t));
}

void	delete_node(t_hbranch *hbranch)
{
	if (!hbranch)
		return ;
	free_node_recursive(hbranch);
	if (hbranch->parent)
		unlink_from_parent(hbranch);
	free(hbranch);
}

void	free_htree(t_htree *htree)
{
	free_ttf(htree->style.font);
	if (htree && htree->body)
		delete_node(htree->body);
	free_vector(&htree->refs);
	free_vector(&htree->free_slots);
}
