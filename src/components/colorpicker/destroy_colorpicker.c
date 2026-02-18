/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_colorpicker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:36:08 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_colorpicker(t_hbranch *colorpicker)
{
	remove_button_hook(colorpicker->head->mlx_data,
		colorpicker->colorpicker._event_click_idx);
	remove_move_hook(colorpicker->head->mlx_data,
		colorpicker->colorpicker._event_move_idx);
}
