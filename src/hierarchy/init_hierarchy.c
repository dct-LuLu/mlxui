/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hierarchy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:50:22 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/06 12:57:15 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

t_htree	init_htree(t_mlx *mlx_data, t_style style)
{
	t_htree	htree;

	htree = (t_htree)
	{
		.mlx_data = mlx_data,
		.style = style
	};
	return (htree);
}

t_hbranch	init_hbranch(t_htree *head, t_hbranch *parent)
{
	t_img_data	*img;
	t_hbranch	hbranch;
	t_hbranch	*_in_scrollbox;

	_in_scrollbox = parent->_in_scrollbox;
	img = parent->img;
	if ((parent->type == SCROLLBOX) && (parent->childs->num_elements == 0))
	{
		_in_scrollbox = parent;
		img = &parent->scrollbox._scroll_buffer;
	}
	hbranch = (t_hbranch)
	{
		.visible = true,
		.rendered = true,
		.parent = parent,
		.head = head,
		.childs = ft_calloc(sizeof(t_vector), 1),
		.img = img,
		._in_scrollbox = _in_scrollbox
	};
	if (!hbranch.childs)
		return (nul_error(pack_err(LFT_ID, LFT_E_ALOC), FL, LN, FC));
	return (hbranch);
}

t_hbranch	*add_branch(t_hbranch *parent_branch)
{
	t_hbranch	new_branch;

	if ((parent_branch->childs == NULL)
		|| (parent_branch->childs->num_elements == 0))
		vector_init(parent_branch->childs, sizeof(t_hbranch));
	new_branch = init_hbranch(parent_branch->head, parent_branch);
	if (!new_branch)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_MSG_IBR), FL, LN, FC));
	if (vector_add(parent_branch->childs, &new_branch, 1) != 0)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_MSG_ABR), FL, LN, FC));//wrong should be vec add error
	return (get_vector_value(parent_branch->childs,
			parent_branch->childs->num_elements - 1));
}
