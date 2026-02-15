/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_slider.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:54:40 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 07:58:23 by jaubry--         ###   ########.fr       */
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

/*
static inline void	update_value_from_pos(t_hbranch *hbranch, int mouse_x)
{
	float	range;
	float	ratio;
	float	raw_value;

	if (!hbranch->slider.value)
		return ;
	range = hbranch->slider.stop - hbranch->slider.start;
	ratio = (float)(mouse_x - hbranch->slider._bar_start.x)
		/ (float)hbranch->slider._bar_width;
	if (ratio < 0.0f)
		ratio = 0.0f;
	if (ratio > 1.0f)
		ratio = 1.0f;
	raw_value = hbranch->slider.start + (ratio * range);
	*hbranch->slider.value = snap_to_step(&hbranch->slider, raw_value);
	printf("slider value: %g\n", *hbranch->slider.value);
	compute_knob_position(hbranch);
}
*/

static inline void	update_value_from_pos(t_hbranch *hbranch, int mouse_x)
{
	float	ratio;
	float	raw_value;

	if (!hbranch->slider.value)
		return ;
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
	*hbranch->slider.value = snap_to_step(&hbranch->slider, raw_value);
	printf("slider value: %g\n", *hbranch->slider.value);
	compute_knob_position(hbranch);
}

static inline void	update_slider_value(t_hbranch *hbranch, t_vec2i pos)
{
	int	mouse_x;

	if (!hbranch->slider.value)
		return ;
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
	(void)mlx_data;
	if (!hbranch->rendered || !hbranch->visible)
		return ;
	if (action == MPRESS && is_inside_bar(hbranch, pos))
	{
		hbranch->slider._dragging = true;
		update_slider_value(hbranch, pos);
	}
	else if (action == MRELEASE)
		hbranch->slider._dragging = false;
	if (hbranch->slider._dragging)
		update_slider_value(hbranch, pos);
}

void	hook_hover_slider(t_hbranch *hbranch, t_mlx *mlx_data)
{
	if (!hbranch->slider._dragging)
		return ;
	update_slider_value(hbranch, mlx_data->mouse_input.pos);
}
