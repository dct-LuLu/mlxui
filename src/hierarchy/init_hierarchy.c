/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hierarchy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:50:22 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/29 21:49:05 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

t_htree	init_htree(t_mlx *mlx_data)
{
	t_htree	htree = (t_htree)
	{
		.mlx_data = mlx_data,
		.style = (t_style)
		{
			.color = rgba_int(30, 30, 30, 200),
			.outline = rgba_int(62, 62, 62, 230),
			.accent = rgba_int(56, 93, 209, 255)
		},
	};
	return (htree);
}

t_hbranch init_hbranch(t_htree *head, t_hbranch *parent, bool hidden)
{
	t_hbranch	hbranch = (t_hbranch)
	{
		.hidden = hidden,
		.parent = parent,
		.head = head,
		.branches = ft_calloc(sizeof(t_vector), 1),
		.box = (t_box)
		{
			.radius = (t_radius) {.style = FULL_PX},
			.border = (t_border)
			{
				.size = 1,
				.color = head->style.outline,
				.style = SOLID
			}
		}
	};

	if (parent == NULL)
	{
		hbranch.box.anchor = LT;
		hbranch.box.size = vec2i_sub_scalar(head->mlx_data->size, 50);
		hbranch.box.pos = vec2i(25, 25);
		hbranch.box.color = head->style.color;
		hbranch.box.radius.full = 20;
	}
	else
	{
		hbranch.box.anchor = CENTER;
		hbranch.box.size = vec2i_div_scalar(parent->box.size, 3);
		hbranch.box.color = head->style.color;
		hbranch.box.radius.full = 5;
	}
	return (hbranch);
}

t_hbranch	*add_branch(t_hbranch *parent_branch, bool hidden)
{
	t_hbranch	new_branch;

	if (parent_branch->branches == NULL || parent_branch->branches->num_elements == 0)
	{
		printf("init\n");
		vector_init(parent_branch->branches, sizeof(t_hbranch));
	}
	printf("add\n");
	new_branch	= init_hbranch(parent_branch->head, parent_branch, hidden);
	vector_add(parent_branch->branches, &new_branch, 1);
	return (get_vector_value(parent_branch->branches, parent_branch->branches->num_elements - 1));
}
