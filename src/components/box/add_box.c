/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:17:12 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/06 12:56:37 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	create_box(t_hbranch *new, t_radius radius, t_border border)
{
	new->box.color = new->head->style.card;
	new->box.radius = radius;
	new->box.border = border;
}

t_hbranch	*add_box(t_hbranch *parent_branch, t_radius radius, t_border border)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (NULL);
	create_box(new, radius, border);
	new->type = BOX;
	new->precompute = precompute_box;
	new->render = (void (*)(t_hbranch *, void *))render_box;
	return (new);
}
