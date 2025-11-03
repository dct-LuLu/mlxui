/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_checkbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 20:44:35 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	render_checkmark(t_hbranch *hbranch, t_checkbox *checkbox)
{
	const t_rgb_int	white = drgb_int(0xFFFFFF);
	t_vec2i	check[3];

	check[0] = vec2i(checkbox->_lt.x + 3, checkbox->_lt.y + 9);
	check[1] = vec2i(checkbox->_lt.x + 7, checkbox->_lt.y + 13);
	check[2] = vec2i(checkbox->_lt.x + 14, checkbox->_lt.y + 6);
	ft_mlx_line_put(&hbranch->head->mlx_data->img, check[0], check[1], white);
	ft_mlx_line_put(&hbranch->head->mlx_data->img, check[1], check[2], white);
}

void	render_checkbox(t_hbranch *hbranch, t_checkbox *checkbox)
{
	render_box(hbranch, &checkbox->box);
	if (checkbox->checked && *checkbox->checked)
		render_checkmark(hbranch, checkbox);
}
