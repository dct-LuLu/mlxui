/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:56:02 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 07:56:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

float	value_to_ratio_linear(t_slider *slider, float value)
{
	float	range;

	range = slider->stop - slider->start;
	if (fabsf(range) < 0.0001f)
		return (0.0f);
	return ((value - slider->start) / range);
}

float	ratio_to_value_linear(t_slider *slider, float ratio)
{
	float	range;

	range = slider->stop - slider->start;
	return (slider->start + (ratio * range));
}

float	value_to_ratio_log(t_slider *slider, float value)
{
	float	log_start;
	float	log_stop;
	float	log_value;

	if (slider->start <= 0.0f || slider->stop <= 0.0f || value <= 0.0f)
		return (value_to_ratio_linear(slider, value));
	log_start = logf(slider->start);
	log_stop = logf(slider->stop);
	log_value = logf(value);
	if (fabsf(log_stop - log_start) < 0.0001f)
		return (0.0f);
	return ((log_value - log_start) / (log_stop - log_start));
}

float	ratio_to_value_log(t_slider *slider, float ratio)
{
	float	log_start;
	float	log_stop;
	float	log_value;

	if (slider->start <= 0.0f || slider->stop <= 0.0f)
		return (ratio_to_value_linear(slider, ratio));
	log_start = logf(slider->start);
	log_stop = logf(slider->stop);
	log_value = log_start + (ratio * (log_stop - log_start));
	return (expf(log_value));
}

