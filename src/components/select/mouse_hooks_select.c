/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_select.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:17:26 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/10 11:44:04 by jaubry--         ###   ########.fr       */
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
	(void)mlx_data;
	if (action == MPRESS && hbranch->select.expanded)
	{
		if (!(((pos.x > hbranch->select.expand->_lt.x) && (pos.x < hbranch->select.expand->_rt.x))
			&& ((pos.y > hbranch->select.expand->_lt.y) && (pos.y < hbranch->select.expand->_lb.y)))
			&& !(((pos.x > hbranch->select.label_box->box._lt.x) && (pos.x < hbranch->select.label_box->box._rt.x))
			&& ((pos.y > hbranch->select.label_box->box._lt.y) && (pos.y < hbranch->select.label_box->box._lb.y)))
			&& !(((pos.x > hbranch->box._lt.x) && (pos.x < hbranch->box._rt.x))
			&& ((pos.y > hbranch->box._lt.y) && (pos.y < hbranch->box._lb.y))))
			switch_select_expand(hbranch, NULL);
	}
}
