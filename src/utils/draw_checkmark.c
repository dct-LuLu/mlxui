/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_checkmark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 02:46:14 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/27 03:19:29 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	draw_checkmark(t_vec2i pos, t_rgba_int color, t_mlx *mlx_data)
{
	t_vec2i	check[3];

	check[0] = vec2i(pos.x + 3, pos.y + 9);
	check[1] = vec2i(pos.x + 7, pos.y + 13);
	check[2] = vec2i(pos.x + 14, pos.y + 6);
	ft_mlx_line_aput(&mlx_data->img, check[0], check[1], color);
	ft_mlx_line_aput(&mlx_data->img, check[1], check[2], color);
}
