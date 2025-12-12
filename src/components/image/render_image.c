/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:28:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/12 17:57:23 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_image(t_hbranch *hbranch, t_image *image)
{
	t_vec2i		pos;
	t_rgb_int	color;
	int			x;
	int			y;

	y = 0;
	while (y < image->img_data.height)
	{
		x = 0;
		while (x < image->img_data.width)
		{
			pos = vec2i(hbranch->_lt.x + x, hbranch->_lt.y + y);
			color = drgb_int((uint32_t)*image->img_data.addr);
			ft_mlx_safe_pixel_put(&hbranch->head->mlx_data->img, pos, color);
			x++;
		}
		y++;
	}
}
