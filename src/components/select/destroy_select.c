/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:17:34 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:18:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	destroy_select(t_hbranch *select)
{
	remove_button_hook_by_func(select->head->mlx_data, select->select._hook_focus);
}
