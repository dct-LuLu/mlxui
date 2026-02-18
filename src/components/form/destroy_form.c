/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:51:33 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:41:05 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks
*/
void	destroy_form(t_hbranch *form)
{
	remove_button_hook(form->head->mlx_data, form->form._event_click_idx);
	remove_key_hook(form->head->mlx_data, form->form._event_enter_idx);
	remove_key_hook(form->head->mlx_data, form->form._event_backspace_idx);
	remove_key_hook(form->head->mlx_data, form->form._event_typing_idx);
}
