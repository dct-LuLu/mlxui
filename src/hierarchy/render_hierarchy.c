/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hierarchy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:30:31 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 21:38:38 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	render_component(t_hbranch *cur)
{
	if (cur->type == BOX)
		cur->render(cur, &cur->box);
	else if (cur->type == CHECKBOX)
		cur->render(cur, &cur->checkbox);
}

static inline void	render_hbranch(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch || !hbranch->render)
		return ;
	if (hbranch->visible)
		render_component(hbranch);
	i = 0;
	while (hbranch->childs && (i < hbranch->childs->num_elements))
	{
		cur = get_vector_value(hbranch->childs, i);
		if (cur->render)
			render_hbranch(cur);
		i++;
	}
}

void	render_hierarchy(t_htree *htree)
{
	if (htree)
		render_hbranch(htree->body);
}
