/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hierarchy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:50:22 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 06:08:34 by jaubry--         ###   ########.fr       */
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
	vector_init(&htree.refs, sizeof(t_hbranch *));
	vector_init(&htree.free_slots, sizeof(size_t));
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

t_hbranch	*add_branch(t_hbranch *parent)
{
	t_hbranch	*new;
	size_t		slot_idx;

	if (!parent->childs)
		parent->childs = ft_calloc(sizeof(t_vector), 1);
	if (parent->childs->num_elements == 0)
		vector_init(parent->childs, sizeof(size_t));
	new = ft_calloc(1, sizeof(t_hbranch));
	if (!new || !init_hbranch(parent->head, parent, new))
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_IBR), FL, LN, FC));
	slot_idx = alloc_slot(parent->head);
	if (vector_add(parent->childs, &slot_idx, 1) != 0)
		return (nul_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	if (slot_idx == parent->head->refs.num_elements)
	{
		if (vector_add(&parent->head->refs, &new, 1) != 0)
			return (nul_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	}
	else
		*(t_hbranch **)get_vector_value(&parent->head->refs, slot_idx) = new;
	return (new);
}
