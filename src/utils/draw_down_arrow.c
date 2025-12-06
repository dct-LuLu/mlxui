/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_down_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 09:57:03 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/06 10:27:29 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	draw_down_arrow(t_vec2i pos, t_rgba_int color, t_mlx *mlx_data)
{
	t_vec2i	arrow[3];

	arrow[0] = vec2i(pos.x + 0, pos.y + 6);
	arrow[1] = vec2i(pos.x + 7, pos.y + 13);
	arrow[2] = vec2i(pos.x + 14, pos.y + 6);
	ft_mlx_line_aput(&mlx_data->img, arrow[0], arrow[1], color);
	ft_mlx_line_aput(&mlx_data->img, arrow[1], arrow[2], color);
}
