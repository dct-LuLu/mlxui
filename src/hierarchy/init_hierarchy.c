/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hierarchy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:50:22 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/09 11:37:15 by jaubry--         ###   ########.fr       */
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

t_hbranch	*init_hbranch(t_htree *head, t_hbranch *parent, t_hbranch *hbranch)
{
	t_img_data	*img;
	t_hbranch	*_in_scrollbox;

	_in_scrollbox = parent->_in_scrollbox;
	img = parent->img;
	if ((parent->type == SCROLLBOX) && (parent->childs->num_elements == 0))
	{
		_in_scrollbox = parent;
		img = &parent->scrollbox._scroll_buffer;
	}
	*hbranch = (t_hbranch)
	{
		.visible = true,
		.rendered = true,
		.parent = parent,
		.head = head,
		.childs = ft_calloc(sizeof(t_vector), 1),
		.img = img,
		._in_scrollbox = _in_scrollbox
	};
	if (!hbranch->childs)
		return (NULL);
	return (hbranch);
}

t_hbranch	*add_branch(t_hbranch *parent_branch)
{
	t_hbranch	*new_branch;

	if (parent_branch->head->refs.num_elements == 0)
		vector_init(&parent_branch->head->refs, sizeof(t_hbranch *));
	if ((parent_branch->childs == NULL)
		|| (parent_branch->childs->num_elements == 0))
		vector_init(parent_branch->childs, sizeof(size_t));
	new_branch = ft_calloc(1, sizeof(t_hbranch));
	if (!new_branch || !init_hbranch(parent_branch->head, parent_branch, new_branch))
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_IBR), FL, LN, FC));
	if (vector_add(parent_branch->childs, &parent_branch->head->refs.num_elements, 1) != 0)
		return (nul_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	if (vector_add(&parent_branch->head->refs, &new_branch, 1) != 0)
		return (nul_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (new_branch);
}
