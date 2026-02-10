/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scrollbox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:03:41 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:47:35 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks and frees internal image buffer
*/
void	destroy_scrollbox(t_hbranch *scrollbox)
{
	remove_button_hook_by_func(scrollbox->head->mlx_data,
		scrollbox->scrollbox._hook_mwheelup);
	remove_button_hook_by_func(scrollbox->head->mlx_data,
		scrollbox->scrollbox._hook_mwheeldown);
	free(scrollbox->scrollbox._scroll_buffer.addr);
}
