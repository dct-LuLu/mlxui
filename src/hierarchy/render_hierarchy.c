/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hierarchy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:30:31 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 00:59:42 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	render_component(t_hbranch *cur)
{
	if ((cur->type == BOX) || (cur->type == FORM) || (cur->type == BUTTON))
		cur->render(cur, &cur->box);
	else if (cur->type == CHECKBOX)
		cur->render(cur, &cur->checkbox);
	else if (cur->type == TEXTBOX)
		cur->render(cur, &cur->textbox);
	else if (cur->type == SELECT)
		cur->render(cur, &cur->select);
	else if (cur->type == IMAGE)
		cur->render(cur, &cur->image);
	else if (cur->type == SCROLLBOX)
		cur->render(cur, &cur->scrollbox);
}

static inline void	render_hbranch(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch)
		return ;
	if (hbranch->visible && hbranch->rendered)
		render_component(hbranch);
	i = 0;
	while (hbranch->rendered && hbranch->childs && (i < hbranch->childs->num_elements))
	{
		cur = get_vector_value(hbranch->childs, i);
		render_hbranch(cur);
		i++;
	}
}

void	render_select_overlay(t_hbranch *hbranch, t_select *select);

static inline void	render_component_overlay(t_hbranch *cur)
{
	if ((cur->type == SELECT) && cur->select.expanded)
		render_select_overlay(cur, &cur->select);
	if (((cur->type == BUTTON) || (cur->type == SELECT)) && cur->button.hover)
		render_button_overlay(cur);
	else if (cur->type == BUTTON_GROUP)
		render_button_overlay(cur);
}

static inline void	render_hbranch_overlay(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch)
		return ;
	if (hbranch->visible && hbranch->rendered)
		render_component_overlay(hbranch);
	i = 0;
	while (hbranch->rendered && hbranch->childs && (i < hbranch->childs->num_elements))
	{
		cur = get_vector_value(hbranch->childs, i);
		render_hbranch_overlay(cur);
		i++;
	}
}

static inline void	render_hbranch_scrollbox(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch)
		return ;
	if (hbranch->visible && hbranch->rendered && (hbranch->type == SCROLLBOX))
		render_scrollbox(hbranch, &hbranch->scrollbox);
	i = 0;
	while (hbranch->rendered && hbranch->childs && (i < hbranch->childs->num_elements))
	{
		cur = get_vector_value(hbranch->childs, i);
		render_hbranch_scrollbox(cur);
		i++;
	}
}

void	render_hierarchy(t_htree *htree)
{
	if (htree)
	{
		render_hbranch(htree->body);
		render_hbranch_overlay(htree->body);
		render_hbranch_scrollbox(htree->body);
	}
}
