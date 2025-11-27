/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:48:37 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/27 04:33:05 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	hook_click_button(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && hbranch->rendered && hbranch->visible
			&& (((pos.x > hbranch->_lt.x) && (pos.x < hbranch->_rt.x))
				&& ((pos.y > hbranch->_lt.y) && (pos.y < hbranch->_lb.y))))
			hbranch->button.action(hbranch, hbranch->button.arg);
}

void	hook_hover_button(t_hbranch *hbranch, t_mlx *mlx_data)
{
	const t_vec2i	pos = mlx_data->mouse_input.pos;
	const bool		hover = hbranch->button.hover;
	const bool		inside = (((pos.x > hbranch->_lt.x) && (pos.x < hbranch->_rt.x))
			&& ((pos.y > hbranch->_lt.y) && (pos.y < hbranch->_lb.y)));

	if (hover && !inside)
	{
		hbranch->button.box.color = hbranch->head->style.card;
		hbranch->button.hover = false;
	}
	else if (!hover && inside)
	{
		hbranch->button.box.color = hbranch->head->style.input;
		hbranch->button.hover = true;
	}
}
