/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 02:13:13 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/14 13:25:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline t_hbranch	*add_form_buffer(t_hbranch *new)
{
	t_hbranch	*textbox;

	textbox = add_textbox(new, (t_text)
		{
			.font_size = 2,
			.fg = (t_rgba_int){.rgba = WHITE},
		}, CENTER_ALIGN, NO_WRAPPING);
	if (!textbox)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "buffer textbox", "form");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	new->form.form_text = &textbox->textbox;
	textbox->anchor = CENTER;
	textbox->x_pos_operation = center_abs_parent;
	textbox->y_pos_operation = center_abs_parent;
	textbox->x_size_operation = copy_parent;
	textbox->y_size_operation = copy_parent;
	return (textbox);
}

static inline t_hbranch	*add_form_morpheme(t_hbranch *new, const char *morpheme)
{
	t_hbranch	*textbox;

	textbox = add_textbox(new, (t_text)
		{
			.font_size = 2,
			.fg = (t_rgba_int){.rgba = WHITE},
		}, LEFT_ALIGN, NO_WRAPPING);
	if (!textbox)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "morpheme textbox", "form");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	new->form.morpheme = &textbox->textbox;
	ft_strlcpy(new->form.morpheme->content, morpheme, FORM_BUF_SIZE);
	textbox->anchor = LEFT;
	textbox->x_pos_operation = form_suffix_pos_x;
	textbox->y_pos_operation = center_abs_parent;
	textbox->x_size_operation = form_suffix_size_x;
	textbox->y_size_operation = copy_parent;
	return (textbox);
}

static inline void	create_form_box(t_hbranch *new)
{
	new->form.box.size = vec2i(160, 36);
	new->form.box.radius.style = FULL_PX;
	new->form.box.radius.full = 9;
	new->form.box.border.style = SOLID;
	new->form.box.border.size = 1;
	new->form.box.color = new->head->style.input;
	new->form.box.border.color = new->head->style.border;
}

void	hook_form_typing(t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_form_enter(t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_form_backspace(t_hbranch *hbranch, t_mlx *mlx_data);

static inline t_hbranch	*create_form(t_hbranch *new, void *value,
						t_form_type type, const char *morpheme)
{
	new->form.value = value;
	new->form.form_type = type;
	if (type == FORM_INT)
	{
		new->form.is_valid_input = form_is_valid_input_int;
		new->form.format_buf = form_format_buf_int;
		new->form._btov = form_btov_int;
		new->form._vtob = form_vtob_int;
	}
	else if (type == FORM_FLOAT)
	{
		new->form.is_valid_input = form_is_valid_input_float;
		new->form.format_buf = form_format_buf_float;
		new->form._btov = form_btov_float;
		new->form._vtob = form_vtob_float;
	}
	new->form._hook_focus = (void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_focus_form;
	new->form._hook_enter = (void (*)(void *, t_mlx *))hook_form_enter;
	new->form._hook_backspace = (void (*)(void *, t_mlx *))hook_form_backspace;
	new->form._hook_typing = (void (*)(void *, t_mlx *))hook_form_typing;
	create_form_box(new);
	if (!add_form_buffer(new))
		return (NULL);
	if ((morpheme != NULL) && !add_form_morpheme(new, morpheme))
		return (NULL);
	return (new);
}

t_hbranch	*add_form(t_hbranch *parent_branch, void *value,
				t_form_type type, const char *morpheme)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	if (!create_form(new, value, type, morpheme))
		return (NULL);
	new->type = FORM;
	new->precompute = precompute_form;
	new->render = (void (*)(t_hbranch *, void *))render_box;
	if (add_func_button_hook(new->head->mlx_data, MLCLICK,
		new->form._hook_focus, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_key_hook(new->head->mlx_data, is_enter_key,
		new->form._hook_enter, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_skey_hook(new->head->mlx_data, XK_BackSpace,
		new->form._hook_backspace, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_key_hook(new->head->mlx_data, is_form_typing_key,
		new->form._hook_typing, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (new);
}
