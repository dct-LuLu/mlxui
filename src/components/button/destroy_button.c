/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:00:52 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:32:19 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks
*/
void	destroy_button(t_hbranch *button)
{
	remove_button_hook(button->head->mlx_data, button->button._event_click_idx);
	remove_move_hook(button->head->mlx_data, button->button._event_move_idx);
}
