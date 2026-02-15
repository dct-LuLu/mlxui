/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_slider.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:53:31 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 07:59:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

/*
void	compute_knob_position(t_hbranch *hbranch)
{
	float	range;
	float	ratio;
	int		offset;

	hbranch->slider._knob_pos = vec2i(hbranch->slider._bar_start.x, hbranch->slider._mid.y);
	if (!hbranch->slider.value)
		return ;
	range = hbranch->slider.stop - hbranch->slider.start;
	if (fabsf(range) < 0.0001f)
		ratio = 0.0f;
	else
		ratio = (*hbranch->slider.value - hbranch->slider.start) / range;
	offset = (int)(ratio * (float)hbranch->slider._bar_width);
	hbranch->slider._knob_pos.x = hbranch->slider._bar_start.x + offset;
}
*/

void	compute_knob_position(t_hbranch *hbranch)
{
	float	ratio;
	int		offset;

	hbranch->slider._knob_pos = vec2i(hbranch->slider._bar_start.x,
			hbranch->_mid.y);
	if (!hbranch->slider.value)
		return ;
	if (hbranch->slider.linear_step)
		ratio = value_to_ratio_linear(&hbranch->slider, *hbranch->slider.value);
	else
		ratio = value_to_ratio_log(&hbranch->slider, *hbranch->slider.value);
	offset = (int)(ratio * (float)hbranch->slider._bar_width);
	hbranch->slider._knob_pos.x = hbranch->slider._bar_start.x + offset;
}

int	precompute_slider(t_hbranch *hbranch)
{
	t_hbranch	*start_text;
	t_hbranch	*end_text;

	hbranch->slider._bar_width = hbranch->size.x
		- (2 * (SLIDER_KNOB_RADIUS + SLIDER_BAR_OFFSET));
	hbranch->slider._bar_start = vec2i(hbranch->_lt.x
			+ SLIDER_KNOB_RADIUS + SLIDER_BAR_OFFSET, hbranch->_mid.y);
	hbranch->slider._bar_end = vec2i(hbranch->_rt.x
			- SLIDER_KNOB_RADIUS - SLIDER_BAR_OFFSET, hbranch->_mid.y);
	start_text = hbranch->slider.start_text;
	end_text = hbranch->slider.end_text;
	strf(start_text->textbox.content, SLIDER_BUF_SIZE,
		"%.2g", hbranch->slider.start);
	strf(end_text->textbox.content, SLIDER_BUF_SIZE,
		"%.2g", hbranch->slider.stop);
	start_text->pos = vec2i(hbranch->slider._bar_start.x
			- 2 - SLIDER_TEXT_OFFSET, hbranch->_mid.y);
	end_text->pos = vec2i(hbranch->slider._bar_end.x
			+ SLIDER_TEXT_OFFSET, hbranch->_mid.y);
	compute_knob_position(hbranch);
	return (0);
}
