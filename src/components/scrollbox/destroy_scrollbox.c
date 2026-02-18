/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scrollbox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:03:41 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:43:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks and frees internal image buffer
*/
void	destroy_scrollbox(t_hbranch *scrollbox)
{
	remove_button_hook(scrollbox->head->mlx_data,
		scrollbox->scrollbox._event_mwheelup_idx);
	remove_button_hook(scrollbox->head->mlx_data,
		scrollbox->scrollbox._event_mwheeldown_idx);
	free(scrollbox->scrollbox._scroll_buffer.addr);
}
