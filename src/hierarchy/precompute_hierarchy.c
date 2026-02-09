/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_hierarchy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:18:35 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/09 17:17:44 by jaubry--         ###   ########.fr       */
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
		cur = get_hbranch_child_idx(hbranch, i);
		if (cur->rendered)
			render_num++;
		i++;
	}
	return (render_num);
}

int	precompute_hbranch(t_hbranch *hbranch)
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
		cur = get_hbranch_child_idx(hbranch, i);
		precompute_geometry(cur, render_i, render_num);
		if (cur->visible && cur->precompute && (cur->precompute(cur) != 0))
			return (1);
		render_i++;
		if (precompute_hbranch(cur) != 0)
			return (1);
		i++;
	}
	return (0);
}

static inline int	precompute_htree(t_hbranch *htree)
{
	int	ret;

	ret = 0;
	precompute_geometry(htree, 0, 1);
	if (htree->visible && htree->precompute)
		ret = htree->precompute(htree);
	if (ret == 0)
		ret = precompute_hbranch(htree);
	return (ret);
}

int	precompute_hierarchy(t_htree *htree)
{
	if (htree)
		return (precompute_htree(htree->body));
	return (1);
}
