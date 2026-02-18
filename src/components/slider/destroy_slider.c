/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_slider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:53:10 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:50:43 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_slider(t_hbranch *slider)
{
	remove_button_hook(slider->head->mlx_data,
		slider->slider._event_click_idx);
	remove_move_hook(slider->head->mlx_data,
		slider->slider._event_move_idx);
}
