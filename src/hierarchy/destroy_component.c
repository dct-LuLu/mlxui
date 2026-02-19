/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_component.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:24:14 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:30:39 by jaubry--         ###   ########.fr       */
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
	else if (hbranch->type == COLORPICKER)
		destroy_colorpicker(hbranch);
}

static inline void	free_node_shallow(t_hbranch *hbranch)
{
	size_t	i;
	size_t	*child_idx;

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

void	free_node_recursive(t_hbranch *hbranch)
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
