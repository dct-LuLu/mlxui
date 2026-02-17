/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_slider.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:54:40 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/17 09:55:08 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

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

static inline float	snap_to_step(t_slider *slider, float value)
{
	float	normalized;
	int		step_count;

	if (fabsf(slider->step) < 0.0001f)
		return (value);
	step_count = roundf((value - slider->start) / slider->step);
	normalized = slider->start + (step_count * slider->step);
	if (normalized < slider->start)
		return (slider->start);
	if (normalized > slider->stop)
		return (slider->stop);
	return (normalized);
}

static inline void	update_value_from_pos(t_hbranch *hbranch, int mouse_x)
{
	float	ratio;
	float	raw_value;

	ratio = (float)(mouse_x - hbranch->slider._bar_start.x)
		/ (float)hbranch->slider._bar_width;
	if (ratio < 0.0f)
		ratio = 0.0f;
	if (ratio > 1.0f)
		ratio = 1.0f;
	if (hbranch->slider.linear_step)
		raw_value = ratio_to_value_linear(&hbranch->slider, ratio);
	else
		raw_value = ratio_to_value_log(&hbranch->slider, ratio);
	hbranch->slider.value = snap_to_step(&hbranch->slider, raw_value);
	if (hbranch->slider.ptr)
		*hbranch->slider.ptr = hbranch->slider.value;
	compute_slider_knob_position(hbranch);
	if (hbranch->slider.action3)
		hbranch->slider.action3(hbranch, hbranch->slider.args3[0],
				hbranch->slider.args3[1], hbranch->slider.args3[2]);
}

static inline void	update_slider_value(t_hbranch *hbranch, t_vec2i pos)
{
	int	mouse_x;

	mouse_x = pos.x;
	if (mouse_x < hbranch->slider._bar_start.x)
		mouse_x = hbranch->slider._bar_start.x;
	if (mouse_x > hbranch->slider._bar_start.x + hbranch->slider._bar_width)
		mouse_x = hbranch->slider._bar_start.x + hbranch->slider._bar_width;
	update_value_from_pos(hbranch, mouse_x);
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
		hbranch->slider._dragging = false;
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
