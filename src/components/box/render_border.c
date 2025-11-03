/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:12:48 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 20:24:03 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_border(t_img_data *img, t_box box)
{
	if ((box.border.style != SOLID) || (box.border.size == 0))
		return ;
	if (box.radius._mem == 0)
		ft_mlx_out_aarec_aput(img, box._ltc.corner, box._rbc.corner, box.border.color);
	else
	{
		if (box.radius.full != 100)
		{
			ft_mlx_hline_aput(img, vec2i(box._ltc.horz.x, box._rtc.horz.x).data,
					box._ltc.corner.y, box.border.color);
			ft_mlx_hline_aput(img, vec2i(box._lbc.horz.x, box._rbc.horz.x).data,
					box._lbc.corner.y, box.border.color);
			ft_mlx_vline_aput(img, vec2i(box._ltc.vert.y, box._lbc.vert.y).data,
					box._ltc.corner.x, box.border.color);
			ft_mlx_vline_aput(img, vec2i(box._rtc.vert.y, box._rbc.vert.y).data,
					box._rtc.corner.x, box.border.color);
		}
		ft_mlx_quad_curve_aput(img, box._ltc._mem, box.border.color);
		ft_mlx_quad_curve_aput(img, box._rtc._mem, box.border.color);
		ft_mlx_quad_curve_aput(img, box._lbc._mem, box.border.color);
		ft_mlx_quad_curve_aput(img, box._rbc._mem, box.border.color);
	}
}
