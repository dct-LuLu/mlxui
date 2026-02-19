/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_slider.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:54:40 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 17:43:44 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	update_slider_value(t_hbranch *hbranch, t_vec2i pos);

static inline bool	is_inside_bar(t_hbranch *hbranch, t_vec2i pos)
{
	int	bar_top_y;
	int	bar_bottom_y;

	bar_top_y = hbranch->slider._bar_start.y - SLIDER_KNOB_RADIUS;
	bar_bottom_y = hbranch->slider._bar_start.y + SLIDER_KNOB_RADIUS;
	return ((pos.x >= (hbranch->slider._bar_start.x - SLIDER_KNOB_RADIUS))
		&& (pos.x <= (hbranch->slider._bar_end.x + SLIDER_KNOB_RADIUS))
		&& (pos.y >= bar_top_y) && (pos.y <= bar_bottom_y));
}

void	hook_drag_slider(t_vec2i pos, t_maction action,
	t_hbranch *hbranch, t_mlx *mlx_data)
{
	t_vec2i	realpos;

	(void)mlx_data;
	if (!hbranch->rendered || !hbranch->visible)
		return ;
	realpos = get_absolute_pos(hbranch, pos);
	if (action == MPRESS && is_inside_bar(hbranch, realpos))
	{
		hbranch->slider._dragging = true;
		update_slider_value(hbranch, realpos);
	}
	else if (action == MRELEASE)
	{
		if (hbranch->slider._dragging && hbranch->slider.action3)
			hbranch->slider.action3(hbranch, hbranch->slider.args3[0],
				hbranch->slider.args3[1], hbranch->slider.args3[2]);
		hbranch->slider._dragging = false;
	}
	if (hbranch->slider._dragging)
		update_slider_value(hbranch, realpos);
}

void	hook_hover_slider(t_hbranch *hbranch, t_mlx *mlx_data)
{
	t_vec2i	realpos;

	if (!hbranch->slider._dragging)
		return ;
	realpos = get_absolute_pos(hbranch, mlx_data->mouse_input.pos);
	update_slider_value(hbranch, realpos);
}
