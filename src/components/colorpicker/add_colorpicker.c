/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colorpicker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:33:44 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 10:10:29 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

static inline t_hbranch	*add_colorpicker_popup(t_hbranch *new)
{
	t_hbranch	*popup;

	popup = add_branch(new);
	if (!popup)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "popup", "colorpicker");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	popup->type = COLORPICKER_POPUP;
	popup->visible = false;
	popup->anchor = BOTTOM;
	popup->render = (void (*)(t_hbranch *, void *))render_colorpicker_popup;
	new->colorpicker.popup = popup;
	return (popup);
}

static inline void	create_colorpicker(t_hbranch *new, t_rgb *value)
{
	new->colorpicker.value = value;
	new->colorpicker.popup_open = false;
	new->colorpicker._dragging = false;
	new->colorpicker._hook_click = (void (*)(t_vec2i, t_maction, void *,
			t_mlx *))hook_click_colorpicker;
	new->colorpicker._hook_hover = (void (*)(void *,
			t_mlx *))hook_hover_colorpicker;
}

static inline void	create_colorpicker_box(t_hbranch *new)
{
	new->size = vec2i(160, 36);
	new->colorpicker.box.size = vec2i(160, 36);
	new->colorpicker.box.radius.style = FULL_PX;
	new->colorpicker.box.radius.full = 9;
	new->colorpicker.box.border.style = SOLID;
	new->colorpicker.box.border.size = 1;
	new->colorpicker.box.border.color = new->head->style.border;
}

t_hbranch	*add_colorpicker(t_hbranch *parent_branch, t_rgb *value)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->type = COLORPICKER;
	new->precompute = precompute_colorpicker;
	new->render = (void (*)(t_hbranch *, void *))render_colorpicker_preview;
	create_colorpicker_box(new);
	create_colorpicker(new, value);
	if (!add_colorpicker_popup(new))
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	if (add_func_button_hook(new->head->mlx_data, MLCLICK,
			new->colorpicker._hook_click, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_move_hook(new->head->mlx_data,
			new->colorpicker._hook_hover, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (new);
}
