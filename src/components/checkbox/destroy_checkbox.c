/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_checkbox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:06:20 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:22:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks
*/
void	destroy_checkbox(t_hbranch *checkbox)
{
	remove_button_hook_by_func(checkbox->head->mlx_data,
		checkbox->checkbox._hook_click);
}
