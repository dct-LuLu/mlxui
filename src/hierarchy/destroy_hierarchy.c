/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hierarchy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:56:06 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 06:03:37 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

static inline void	free_component_data(t_hbranch *hbranch)
{
	if (hbranch->type == BUTTON)
		destroy_button(hbranch);
	else if (hbranch->type == CHECKBOX)
		destroy_checkbox(hbranch);
	else if (hbranch->type == FORM)
		destroy_form(hbranch);
	else if (hbranch->type == IMAGE)
		destroy_image(hbranch);
	else if ((hbranch->type == SCROLLBOX) && hbranch->parent
			&& (hbranch->parent->type != SCROLLBOX))
		destroy_scrollbox(hbranch);
	else if (hbranch->type == SELECT)
		destroy_select(hbranch);
	else if (hbranch->type == SLIDER)
		destroy_slider(hbranch);
}

static inline void    free_node_shallow(t_hbranch *hbranch)
{
    size_t      i;
    size_t      *child_idx;

    free_component_data(hbranch);
    if (!hbranch->childs || !hbranch->childs->data)
        return ;
    i = 0;
    while (i < hbranch->childs->num_elements)
    {
        child_idx = (size_t *)get_vector_value(hbranch->childs, i);
        release_slot(hbranch->head, *child_idx);
        i++;
    }
    free_vector(hbranch->childs);
    free(hbranch->childs);
}

static inline void    unlink_from_parent(t_hbranch *hbranch)
{
    size_t      i;
    size_t      *child_idx;
    t_hbranch   *candidate;

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

static inline void	free_node_recursive(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*child;

	i = 0;
	while (hbranch->childs && hbranch->childs->data
			&& (i < hbranch->childs->num_elements))
	{
		child = get_hbranch_child_idx(hbranch, i);
		if (child)
		{
			free_node_recursive(child);
			free(child);
			child = NULL;
		}
		i++;
	}
	free_node_shallow(hbranch);
}

void delete_node_childs(t_hbranch *parent)
{
    size_t      i;
    t_hbranch   *child;

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

void    free_htree(t_htree *htree)
{
    size_t      i;
    t_hbranch   *node;

    i = 0;
    while (i < htree->refs.num_elements)
    {
        node = ref_at(htree, i);
        if (node)
            free(node);
        i++;
    }
    free_vector(&htree->refs);
    free_vector(&htree->free_slots);
}
