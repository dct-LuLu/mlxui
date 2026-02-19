/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_form_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:38:23 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:57:16 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	hook_form_typing(t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_form_enter(t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_form_backspace(t_hbranch *hbranch, t_mlx *mlx_data);

t_hbranch	*create_form_hooks(t_hbranch *form)
{
	form->form._event_click_idx = add_func_button_hook(form->head->mlx_data,
			MLCLICK, (t_button_action *)hook_focus_form, form);
	if (form->form._event_click_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	form->form._event_enter_idx = add_func_key_hook(form->head->mlx_data,
			is_enter_key, (t_move_action *)hook_form_enter, form);
	if (form->form._event_enter_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	form->form._event_backspace_idx = add_func_skey_hook(form->head->mlx_data,
			XK_BackSpace, (t_move_action *)hook_form_backspace, form);
	if (form->form._event_backspace_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	form->form._event_typing_idx = add_func_key_hook(form->head->mlx_data,
			is_form_typing_key, (t_move_action *)hook_form_typing, form);
	if (form->form._event_typing_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (form);
}
