/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_slider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:53:10 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 05:56:39 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_slider(t_hbranch *slider)
{
	remove_button_hook_by_func(slider->head->mlx_data,
		slider->slider._hook_drag);
	remove_move_hook_by_func(slider->head->mlx_data,
		slider->slider._hook_hover);
}
