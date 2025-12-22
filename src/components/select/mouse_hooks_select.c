/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_select.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:17:26 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 00:18:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	switch_select_expand(t_hbranch *hbranch, void *arg)
{
	(void)arg;
	hbranch->select.expanded = !hbranch->select.expanded;
	hbranch->select.label_box->rendered = !hbranch->select.label_box->rendered;
}

void	hook_click_outside_select(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data)
{
	//const t_vec2i	realpos = vec2i_sub(pos, hbranch->_offset);

	(void)mlx_data;
	if (action == MPRESS && hbranch->select.expanded)
	{
		/*
			printf("hello %d %d %d\n", !is_inside_comp(hbranch->select.expand, pos),
					!is_inside_comp(hbranch->select.label_box, pos),
					!is_inside_comp(hbranch, pos));
		*/
		if (!is_inside_comp(hbranch->select.expand, pos)
				&& !is_inside_comp(hbranch->select.label_box, pos)
				&& !is_inside_comp(hbranch, pos))
		{
		/*if (!(((realpos.x > hbranch->select.expand->_lt.x) && (realpos.x < hbranch->select.expand->_rt.x))
			&& ((realpos.y > hbranch->select.expand->_lt.y) && (realpos.y < hbranch->select.expand->_lb.y)))

			&& !(((realpos.x > hbranch->select.label_box->box._lt.x) && (realpos.x < hbranch->select.label_box->box._rt.x))
			&& ((realpos.y > hbranch->select.label_box->box._lt.y) && (realpos.y < hbranch->select.label_box->box._lb.y)))

			&& !(((realpos.x > hbranch->box._lt.x) && (realpos.x < hbranch->box._rt.x))
			&& ((realpos.y > hbranch->box._lt.y) && (realpos.y < hbranch->box._lb.y))))*/
			switch_select_expand(hbranch, NULL);
		}
	}
}
