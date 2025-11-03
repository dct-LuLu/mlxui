/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hierarchy_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:26:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 11:59:59 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

/*
static inline bool	is_bidirectionality_invalid(t_hbranch *parent, t_hbranch *child)
{
	return (((parent->rpos.x.type == ADAPT) && (child->rpos.x.type == INHERIT))
			|| ((parent->rpos.y.type == ADAPT) && (child->rpos.y.type == INHERIT))
			|| ((parent->rsize.x.type == ADAPT) && (child->rsize.x.type == INHERIT))
			|| ((parent->rsize.y.type == ADAPT) && (child->rsize.y.type == INHERIT)));
}
*/

/*
bool	is_tree_valid(t_hbranch *current_branch)
{
	size_t		i;
	t_hbranch	*child;

	if (current_branch->branches == NULL)
		return (true);
	i = 0;
	while (i < current_branch->branches->num_elements)
	{
		child = get_vector_value(current_branch->branches, i);
		if (is_bidirectionality_invalid(current_branch, child))
			return (false);
		if (is_tree_valid(child) == false)
			return (false);
		i++;
	}
	return (true);
}
*/
