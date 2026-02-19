/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_colorpicker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 17:02:39 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline bool	is_inside_circle(t_hbranch *hbranch, t_vec2i pos)
{
	int		dx;
	int		dy;
	float	dist;

	dx = pos.x - hbranch->colorpicker._circle_center.x;
	dy = pos.y - hbranch->colorpicker._circle_center.y;
	dist = sqrtf((float)((dx * dx) + (dy * dy)));
	return (dist <= (float)CPICKER_CIRCLE_RADIUS);
}

static inline void	update_color_from_pos(t_hbranch *hbranch, t_vec2i pos)
{
	int		dx;
	int		dy;
	float	dist;
	float	angle;
	float	sat;

	dx = pos.x - hbranch->colorpicker._circle_center.x;
	dy = pos.y - hbranch->colorpicker._circle_center.y;
	dist = sqrtf((float)((dx * dx) + (dy * dy)));
	if (dist > (float)CPICKER_CIRCLE_RADIUS)
		dist = (float)CPICKER_CIRCLE_RADIUS;
	angle = atan2f((float)dy, (float)dx);
	if (angle < 0.0f)
		angle += 2.0f * M_PI;
	sat = dist / (float)CPICKER_CIRCLE_RADIUS;
	hbranch->colorpicker.rgb = hsv_to_rgb(angle / (2.0f * M_PI), sat, 1.0f);
	compute_colorpicker_knob_position(hbranch);
}

static inline void	hook_click_press(t_vec2i pos, t_vec2i realpos,
						t_hbranch *hbranch)
{
	if (is_inside_comp(hbranch, pos))
	{
		hbranch->colorpicker.popup->visible = true;
		hbranch->colorpicker.popup_open
			= !hbranch->colorpicker.popup_open;
		if (hbranch->colorpicker.popup_open)
			compute_colorpicker_knob_position(hbranch);
	}
	else if (hbranch->colorpicker.popup_open
		&& is_inside_circle(hbranch, realpos))
	{
		hbranch->colorpicker._dragging = true;
		update_color_from_pos(hbranch, realpos);
	}
	else if (hbranch->colorpicker.popup_open
		&& !is_inside_circle(hbranch, realpos))
		hbranch->colorpicker.popup_open = false;
}

void	hook_click_colorpicker(t_vec2i pos, t_maction action,
	t_hbranch *hbranch, t_mlx *mlx_data)
{
	t_vec2i	realpos;

	(void)mlx_data;
	if (!hbranch->rendered || !hbranch->visible)
		return ;
	realpos = get_absolute_pos(hbranch, mlx_data->mouse_input.pos);
	if (action == MPRESS)
		hook_click_press(pos, realpos, hbranch);
	else if (action == MRELEASE)
	{
		if (hbranch->colorpicker._dragging && hbranch->colorpicker.action3)
			hbranch->colorpicker.action3(hbranch, hbranch->colorpicker.args3[0],
				hbranch->colorpicker.args3[1], hbranch->colorpicker.args3[2]);
		hbranch->colorpicker._dragging = false;
	}
}

void	hook_hover_colorpicker(t_hbranch *hbranch, t_mlx *mlx_data)
{
	t_vec2i	realpos;

	if (!hbranch->colorpicker._dragging)
		return ;
	realpos = get_absolute_pos(hbranch, mlx_data->mouse_input.pos);
	update_color_from_pos(hbranch, realpos);
}
