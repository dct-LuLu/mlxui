/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slider.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:53:18 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 08:03:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

static inline t_hbranch	*add_slider_start_text(t_hbranch *new)
{
	t_hbranch	*textbox;

	textbox = add_textbox(new, (t_text){
		.font_size = 2,
		.fg = (t_rgba_int){.rgba = WHITE},
	}, RIGHT_ALIGN, NO_WRAPPING);
	if (!textbox)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "start textbox", "slider");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	textbox->anchor = RIGHT;
	textbox->textbox.vert_align = MIDDLE_ALIGN;
	new->slider.start_text = textbox;
	return (textbox);
}

static inline t_hbranch	*add_slider_end_text(t_hbranch *new)
{
	t_hbranch	*textbox;

	textbox = add_textbox(new, (t_text){
		.font_size = 2,
		.fg = (t_rgba_int){.rgba = WHITE},
	}, LEFT_ALIGN, NO_WRAPPING);
	if (!textbox)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "end textbox", "slider");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	textbox->anchor = LEFT;
	textbox->textbox.vert_align = MIDDLE_ALIGN;
	new->slider.end_text = textbox;
	return (textbox);
}

static inline float	compute_default_step(float start, float stop)
{
	float	range;

	range = fabsf(stop - start);
	if (range > 100.0f)
		return (1.0f);
	else if (range > 10.0f)
		return (0.1f);
	else if (range > 1.0f)
		return (0.01f);
	return (0.001f);
}

static inline void	create_slider(t_hbranch *new, float *value,
		float start, float stop)
{
	new->slider.start = start;
	new->slider.stop = stop;
	new->slider.step = compute_default_step(start, stop);
	new->slider.value = value;
	new->slider.linear_step = true;
	new->slider._dragging = false;
	new->slider._hook_drag = (void (*)(t_vec2i, t_maction, void *,
			t_mlx *))hook_drag_slider;
	new->slider._hook_hover = (void (*)(void *, t_mlx *))hook_hover_slider;
}

t_hbranch	*add_slider(t_hbranch *parent_branch, float *value,
		float start, float stop)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->type = SLIDER;
	new->precompute = precompute_slider;
	new->render = (void (*)(t_hbranch *, void *))render_slider;
	create_slider(new, value, start, stop);
	if (!add_slider_start_text(new) || !add_slider_end_text(new))
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	if (add_func_button_hook(new->head->mlx_data, MLCLICK,
			new->slider._hook_drag, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_move_hook(new->head->mlx_data,
			new->slider._hook_hover, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (new);
}
