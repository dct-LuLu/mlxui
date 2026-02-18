/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:17:34 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:45:45 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_select(t_hbranch *select)
{
	remove_button_hook(select->head->mlx_data, select->select._event_click_idx);
}
