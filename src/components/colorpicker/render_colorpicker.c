/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colorpicker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/16 20:20:59 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_colorpicker_preview(t_hbranch *hbranch, t_colorpicker *colorpicker)
{
	const t_rgb_int	col = rgb_ftoi(colorpicker->rgb);

	hbranch->colorpicker.box.color = rgba_int(col.r, col.g, col.b, 255);
	render_box(hbranch, &hbranch->colorpicker.box);
}

static inline void	render_color_circle(t_hbranch *popup)
{
	int			y;
	int			x;
	t_vec2i		pixel;
	float		dist;
	float		angle;
	float		sat;
	t_rgb		color;
	t_rgb_int	color_int;

	y = -CPICKER_CIRCLE_RADIUS;
	while (y <= CPICKER_CIRCLE_RADIUS)
	{
		x = -CPICKER_CIRCLE_RADIUS;
		while (x <= CPICKER_CIRCLE_RADIUS)
		{
			dist = sqrtf((float)(x * x) + (float)(y * y));
			if (dist <= (float)CPICKER_CIRCLE_RADIUS)
			{
				angle = atan2f((float)y, (float)x);
				if (angle < 0.0f)
					angle += 2.0f * M_PI;
				sat = dist / (float)CPICKER_CIRCLE_RADIUS;
				color = hsv_to_rgb(angle / (2.0f * M_PI), sat, 1.0f);
				color_int = rgb_ftoi(color);
				pixel = vec2i(popup->_mid.x + x, popup->_mid.y + y);
				ft_mlx_safe_pixel_aput(popup->img, pixel, rgba_int(color_int.r, color_int.g, color_int.b, 255));
			}
			x++;
		}
		y++;
	}
}

static inline void	render_color_knob(t_hbranch *hbranch)
{
	ft_mlx_out_circle_aput(hbranch->img, hbranch->colorpicker._knob_pos,
		CPICKER_KNOB_RADIUS, (t_rgba_int){.rgba = 0xFF000000});
}

void	render_colorpicker_popup(t_hbranch *hbranch, t_colorpicker *colorpicker)
{
	t_hbranch	*parent;

	parent = hbranch->parent;
	if (!parent || !colorpicker->popup_open)
		return ;
	ft_mlx_circle_aput(hbranch->img, hbranch->_mid, CPICKER_CIRCLE_RADIUS + 1, hbranch->head->style.border);
	render_color_circle(hbranch);
	render_color_knob(parent);
}
