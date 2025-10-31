/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_hierarchy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:18:35 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/30 18:19:06 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static void	precompute_hbranch(t_hbranch *hbranch)
{
	size_t		i;
	t_hbranch	*cur;

	if (!hbranch || hbranch->hidden)
		return ;
	i = 0;
	precompute_box(&hbranch->box);
	while (hbranch->branches && (i < hbranch->branches->num_elements))
	{
		cur = get_vector_value(hbranch->branches, i);
		cur->box.anchor = LEFT;
		cur->box.pos = vec2i(
				hbranch->box._lt.corner.x + ((hbranch->box.size.x - (cur->box.size.x * hbranch->branches->num_elements)) / (hbranch->branches->num_elements + 1)) * (i + 1) + (i * cur->box.size.x),
				hbranch->box._lt.corner.y + hbranch->box.size.y / 2
				);
		precompute_hbranch(cur);
		i++;
	}
}

void	precompute_hierarchy(t_htree *htree)
{
	if (htree->body)
		precompute_hbranch(htree->body);
}
