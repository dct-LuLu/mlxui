/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_slider_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:41:09 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 17:42:15 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

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
}

void	update_slider_value(t_hbranch *hbranch, t_vec2i pos)
{
	int	mouse_x;

	mouse_x = pos.x;
	if (mouse_x < hbranch->slider._bar_start.x)
		mouse_x = hbranch->slider._bar_start.x;
	if (mouse_x > hbranch->slider._bar_start.x + hbranch->slider._bar_width)
		mouse_x = hbranch->slider._bar_start.x + hbranch->slider._bar_width;
	update_value_from_pos(hbranch, mouse_x);
}
