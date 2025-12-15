/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:28:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/15 10:14:56 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_image(t_hbranch *hbranch, t_image *image)
{
	t_vec2i		pos;
	t_rgba_int	color;
	int			x;
	int			y;

	y = 0;
	while (y < image->img_data.height)
	{
		x = 0;
		while (x < image->img_data.width)
		{
			pos = vec2i(hbranch->_lt.x + x, hbranch->_lt.y + y);
			color.r = image->img_data.pixel[y * image->img_data.line_len + x * image->img_data.byte_depth];
			color.g = image->img_data.pixel[y * image->img_data.line_len + x * image->img_data.byte_depth + 1];
			color.b = image->img_data.pixel[y * image->img_data.line_len + x * image->img_data.byte_depth + 2];
			color.a = image->img_data.pixel[y * image->img_data.line_len + x * image->img_data.byte_depth + 3];
			if (color.rgba != 0)
				ft_mlx_safe_pixel_aput(&hbranch->head->mlx_data->img, pos, color);
			x++;
		}
		y++;
	}
}
