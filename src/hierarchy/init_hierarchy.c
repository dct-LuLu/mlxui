/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hierarchy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:50:22 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/22 00:08:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

t_htree	init_htree(t_mlx *mlx_data, t_style style)
{
	t_htree	htree = (t_htree)
	{
		.mlx_data = mlx_data,
		.style = style
	};
	return (htree);
}

t_hbranch init_hbranch(t_htree *head, t_hbranch *parent)
{
	t_img_data	*img;
	t_hbranch	hbranch;

	if (parent->type == SCROLLBOX)
		img = &parent->scrollbox._scroll_buffer;
	else
		img = parent->img;
	hbranch = (t_hbranch)
	{
		.visible = true,
		.rendered = true,
		.parent = parent,
		.head = head,
		.childs = ft_calloc(sizeof(t_vector), 1),
		.img = img,
	};
	return (hbranch);
}

t_hbranch	*add_branch(t_hbranch *parent_branch)
{
	t_hbranch	new_branch;

	if ((parent_branch->childs == NULL) || (parent_branch->childs->num_elements == 0))
		vector_init(parent_branch->childs, sizeof(t_hbranch));
	new_branch = init_hbranch(parent_branch->head, parent_branch);
	vector_add(parent_branch->childs, &new_branch, 1);
	return (get_vector_value(parent_branch->childs, parent_branch->childs->num_elements - 1));
}
