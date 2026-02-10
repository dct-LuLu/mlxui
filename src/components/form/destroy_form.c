/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:51:33 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 11:20:46 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

/*
	Removes key hooks
*/
void	destroy_form(t_hbranch *form)
{
	remove_button_hook_by_func(form->head->mlx_data, form->form._hook_focus);
	remove_key_hook_by_func(form->head->mlx_data, form->form._hook_enter);
	remove_key_hook_by_func(form->head->mlx_data, form->form._hook_backspace);
	remove_key_hook_by_func(form->head->mlx_data, form->form._hook_typing);
}
