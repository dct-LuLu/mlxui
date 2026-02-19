/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorpicker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:59:43 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline t_rgb	get_rgb_from_sector(int h_sector, float c, float x)
{
	if (h_sector == 0)
		return (vec3(c, x, 0.0f));
	else if (h_sector == 1)
		return (vec3(x, c, 0.0f));
	else if (h_sector == 2)
		return (vec3(0.0f, c, x));
	else if (h_sector == 3)
		return (vec3(0.0f, x, c));
	else if (h_sector == 4)
		return (vec3(x, 0.0f, c));
	else
		return (vec3(c, 0.0f, x));
}

t_rgb	hsv_to_rgb(float h, float s, float v)
{
	float	c;
	float	x;
	float	m;
	t_rgb	rgb_prime;
	int		h_sector;

	c = v * s;
	h_sector = (int)(h * 6.0f);
	if (h_sector >= 6)
		h_sector = 5;
	x = c * (1.0f - fabsf(fmodf(h * 6.0f, 2.0f) - 1.0f));
	m = v - c;
	rgb_prime = get_rgb_from_sector(h_sector, c, x);
	return (rgb_add_scalar(rgb_prime, m));
}

void	rgb_to_hsv(t_rgb rgb, float *h, float *s, float *v)
{
	float	max;
	float	min;
	float	delta;

	max = fmaxf(fmaxf(rgb.x, rgb.y), rgb.z);
	min = fminf(fminf(rgb.x, rgb.y), rgb.z);
	delta = max - min;
	*v = max;
	if (max < 0.0001f)
		*s = 0.0f;
	else
		*s = delta / max;
	if (delta < 0.0001f)
		*h = 0.0f;
	else if (max == rgb.x)
		*h = fmodf((rgb.y - rgb.z) / delta, 6.0f) / 6.0f;
	else if (max == rgb.y)
		*h = ((rgb.z - rgb.x) / delta + 2.0f) / 6.0f;
	else
		*h = ((rgb.x - rgb.y) / delta + 4.0f) / 6.0f;
	if (*h < 0.0f)
		*h += 1.0f;
}
