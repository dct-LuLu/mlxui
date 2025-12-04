/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hierarchy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:30:31 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/04 19:16:01 by jaubry--         ###   ########.fr       */
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
}

static inline void	render_hbranch(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch)
		return ;
	if (hbranch->visible && hbranch->render)
		render_component(hbranch);
	i = 0;
	while (hbranch->childs && (i < hbranch->childs->num_elements))
	{
		cur = get_vector_value(hbranch->childs, i);
		render_hbranch(cur);
		i++;
	}
}

static inline void	render_component_special(t_hbranch *cur)
{
	if ((cur->type == BUTTON) && cur->button.hover)
		render_button_hover(cur);
	else if (cur->type == BUTTON_GROUP)
		render_button_group_switch(cur);
}

static inline void	render_hbranch_special(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch)
		return ;
	if (hbranch->visible)
		render_component_special(hbranch);
	i = 0;
	while (hbranch->childs && (i < hbranch->childs->num_elements))
	{
		cur = get_vector_value(hbranch->childs, i);
		render_hbranch_special(cur);
		i++;
	}
}

void	render_hierarchy(t_htree *htree)
{
	if (htree)
	{
		render_hbranch(htree->body);
		render_hbranch_special(htree->body);
	}
}
