/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colorpicker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 17:39:31 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_colorpicker_preview(t_hbranch *hbranch,
			t_colorpicker *colorpicker)
{
	const t_rgb_int	col = rgb_ftoi(colorpicker->rgb);

	hbranch->colorpicker.box.color = rgba_int(col.r, col.g, col.b, 255);
	render_box(hbranch, &hbranch->colorpicker.box);
}

static inline t_rgba_int	get_color_circle(float dist, float angle)
{
	t_rgb_int	temp;

	temp = rgb_ftoi(hsv_to_rgb(angle / (2.0f * M_PI),
				dist / (float)CPICKER_CIRCLE_RADIUS, 1.0f));
	return (rgba_int(temp.r, temp.g, temp.b, 255));
}

static inline void	render_color_circle(t_hbranch *popup)
{
	t_vec2i		pos;
	float		dist;
	float		angle;

	pos = vec2i(-CPICKER_CIRCLE_RADIUS, -CPICKER_CIRCLE_RADIUS);
	while (pos.y <= CPICKER_CIRCLE_RADIUS)
	{
		pos.x = -CPICKER_CIRCLE_RADIUS;
		while (pos.x <= CPICKER_CIRCLE_RADIUS)
		{
			dist = sqrtf((float)(pos.x * pos.x) + (float)(pos.y * pos.y));
			if (dist <= (float)CPICKER_CIRCLE_RADIUS)
			{
				angle = atan2f((float)pos.y, (float)pos.x);
				if (angle < 0.0f)
					angle += 2.0f * M_PI;
				ft_mlx_safe_pixel_aput(popup->img, vec2i_add(popup->_mid, pos),
					get_color_circle(dist, angle));
			}
			pos.x++;
		}
		pos.y++;
	}
}

static inline void	render_color_knob(t_hbranch *hbranch)
{
	ft_mlx_out_circle_aput(hbranch->img, hbranch->colorpicker._knob_pos,
		CPICKER_KNOB_RADIUS, (t_rgba_int){.rgba = 0xFF000000});
}

void	render_colorpicker_popup(t_hbranch *hbranch,
			t_colorpicker *colorpicker)
{
	t_hbranch	*parent;

	parent = hbranch->parent;
	if (!parent || !colorpicker->popup_open)
		return ;
	ft_mlx_circle_aput(hbranch->img, hbranch->_mid,
		CPICKER_CIRCLE_RADIUS + 1, hbranch->head->style.border);
	render_color_circle(hbranch);
	render_color_knob(parent);
}
