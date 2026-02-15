/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_colorpicker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 10:43:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	compute_knob_position(t_hbranch *hbranch)
{
	float	h;
	float	s;
	float	v;
	float	angle;
	float	radius;

	if (!hbranch->colorpicker.value)
		return ;
	rgb_to_hsv(*hbranch->colorpicker.value, &h, &s, &v);
	angle = h * 2.0f * M_PI;
	radius = s * (float)CPICKER_CIRCLE_RADIUS;
	hbranch->colorpicker._knob_pos.x = hbranch->colorpicker._circle_center.x
		+ (int)(cosf(angle) * radius);
	hbranch->colorpicker._knob_pos.y = hbranch->colorpicker._circle_center.y
		+ (int)(sinf(angle) * radius);
}

int	precompute_colorpicker(t_hbranch *hbranch)
{
	t_hbranch	*popup;

	precompute_box(hbranch);
	popup = hbranch->colorpicker.popup;
	if (popup)
	{
		popup->size = vec2i(CPICKER_POPUP_SIZE, CPICKER_POPUP_SIZE);
		popup->pos = vec2i(hbranch->_mid.x, hbranch->_lt.y);
		precompute_hbranch(hbranch);
		hbranch->colorpicker._circle_center = popup->_mid;
		compute_knob_position(hbranch);
	}
	return (0);
}
