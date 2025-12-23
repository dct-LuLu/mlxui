/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_select.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:17:26 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:22:15 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	switch_select_expand(t_hbranch *hbranch, void *arg)
{
	(void)arg;
	hbranch->select.expanded = !hbranch->select.expanded;
	hbranch->select.label_box->rendered = !hbranch->select.label_box->rendered;
}

void	hook_click_outside_select(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if (action == MPRESS && hbranch->select.expanded
		&& !is_inside_comp(hbranch->select.expand, pos)
		&& !is_inside_comp(hbranch->select.label_box, pos)
		&& !is_inside_comp(hbranch, pos))
		switch_select_expand(hbranch, NULL);
}
