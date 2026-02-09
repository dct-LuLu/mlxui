/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hierarchy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:56:06 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/09 14:43:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_comp(t_hbranch *hbranch)
{
	if (hbranch->type == IMAGE)
		free(hbranch->image.img_data.addr);
	else if ((hbranch->type == SCROLLBOX) && hbranch->parent
			&& (hbranch->parent->type != SCROLLBOX))
		free(hbranch->scrollbox._scroll_buffer.addr);
}

void	destroy_hbranch(t_hbranch *hbranch)
{
	size_t	i;
	size_t	*refs_idx;

	i = 0;
	destroy_comp(hbranch);
	if (!hbranch->childs || !hbranch->childs->data)
		return ;
	refs_idx = hbranch->childs->data;
	while (i < hbranch->childs->num_elements)
	{
		remove_vector_elem(&hbranch->head->refs, refs_idx[i]);
		i++;
	}
	free_vector(hbranch->childs);
	free(hbranch->childs);
}

void	remove_from_parent(t_hbranch *parent, t_hbranch *hbranch)
{
	size_t	i;
	size_t	*refs_idx;

	i = 0;
	refs_idx = parent->childs->data;
	while (i < parent->childs->num_elements)
	{
		if (hbranch == get_hbranch_child_idx(parent, i))
		{
			remove_vector_elem(&hbranch->head->refs, refs_idx[i]);
			remove_vector_elem(parent->childs, i);
			return ;
		}
		i++;
	}
}

void	destroy_hierarchy(t_hbranch *hbranch)
{
	size_t	i;

	i = 0;
	while (hbranch->childs && hbranch->childs->data && (i < hbranch->childs->num_elements))
	{
		destroy_hierarchy(get_hbranch_child_idx(hbranch, i));
		i++;
	}
	destroy_hbranch(hbranch);
}

void	destroy_node(t_hbranch *hbranch)
{
	destroy_hierarchy(hbranch);
	if (hbranch->parent)
		remove_from_parent(hbranch->parent, hbranch);
}
