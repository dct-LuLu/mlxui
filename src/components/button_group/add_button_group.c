/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_button_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:08:20 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:56:09 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

t_hbranch	*add_button_group(t_hbranch *parent_branch,
				t_group_dir group_dir, t_group_type group_type)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->type = BUTTON_GROUP;
	new->button_group.group_dir = group_dir;
	new->button_group.group_type = group_type;
	new->precompute = precompute_button_group;
	return (new);
}
