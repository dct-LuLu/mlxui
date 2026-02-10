/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:00:52 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:22:41 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks
*/
void	destroy_button(t_hbranch *button)
{
	remove_button_hook_by_func(button->head->mlx_data,
		button->button._hook_click);
	remove_move_hook_by_func(button->head->mlx_data,
		button->button._hook_hover);
}
