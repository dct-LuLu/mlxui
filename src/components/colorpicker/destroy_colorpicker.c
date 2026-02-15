/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_colorpicker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:31:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 08:34:07 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_colorpicker(t_hbranch *colorpicker)
{
	remove_button_hook_by_func(colorpicker->head->mlx_data,
		colorpicker->colorpicker._hook_click);
	remove_move_hook_by_func(colorpicker->head->mlx_data,
		colorpicker->colorpicker._hook_hover);
}
