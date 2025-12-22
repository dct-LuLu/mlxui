/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_hierarchy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:18:35 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/22 00:10:49 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline size_t	get_render_num(t_hbranch *hbranch)
{
	size_t		i;
	size_t		render_num;
	t_hbranch	*cur;

	i = 0;
	render_num = 0;
	while (i < hbranch->childs->num_elements)
	{
		cur = get_vector_value(hbranch->childs, i);
		if (cur->rendered)
			render_num++;
		i++;
	}
	return (render_num);
}

void	precompute_hbranch(t_hbranch *hbranch)
{
	size_t		i;
	size_t		render_i;
	size_t		render_num;
	t_hbranch	*cur;

	i = 0;
	render_i = 0;
	render_num = get_render_num(hbranch);
	while (i < hbranch->childs->num_elements)
	{
		cur = get_vector_value(hbranch->childs, i);
		precompute_geometry(cur, render_i, render_num);
		if (cur->visible && cur->precompute)
			cur->precompute(cur);
		render_i++;
		precompute_hbranch(cur);
		i++;
	}
}

static inline void	precompute_htree(t_hbranch *htree)
{
	precompute_geometry(htree, 0, 1);
	if (htree->visible && htree->precompute)
		htree->precompute(htree);
	precompute_hbranch(htree);
}

void	precompute_hierarchy(t_htree *htree)
{
	if (htree)
		precompute_htree(htree->body);
}
