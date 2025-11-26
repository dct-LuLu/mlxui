/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 02:13:13 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/26 21:41:05 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	add_form_buffer(t_hbranch *new)
{
	t_hbranch	*textbox;

	textbox = add_textbox(new,
			(t_text)
			{
				.font_size = 2,
				.fg = (t_rgba_int){.rgba=WHITE}, // necessary?
			}, CENTER_ALIGN, NO_WRAPPING);
	new->form.form_text = &textbox->textbox;
	textbox->anchor = CENTER;
	textbox->x_pos_operation = center_abs_parent;
	textbox->y_pos_operation = center_abs_parent;
	textbox->x_size_operation = copy_parent;
	textbox->y_size_operation = copy_parent;
	// copy value to str into last_form_buf and new form_text
}

static inline void	add_form_morpheme(t_hbranch *new, const char *morpheme)
{
	t_hbranch	*textbox;

	textbox = add_textbox(new,
			(t_text)
			{
				.font_size = 2,
				.fg = (t_rgba_int){.rgba=WHITE},
			}, LEFT_ALIGN, NO_WRAPPING);
	new->form.morpheme = &textbox->textbox;
	ft_strlcpy(new->form.morpheme->content, morpheme, FORM_BUF_SIZE);
	textbox->anchor = LEFT;
	textbox->x_pos_operation = form_suffix_pos_x;
	textbox->y_pos_operation = center_abs_parent;
	textbox->x_size_operation = form_suffix_size_x;
	textbox->y_size_operation = copy_parent;
}

static inline void	create_form_box(t_hbranch *new)
{
	new->form.box.size = vec2i(160, 35);
	new->form.box.radius.style = FULL_PX;
	new->form.box.radius.full = 9;
	new->form.box.border.style = SOLID;
	new->form.box.border.size = 1;
	new->form.box.color = new->head->style.color;
	new->form.box.border.color = new->head->style.outline;
}

static inline void	create_form(t_hbranch *new, void *value, t_form_type type, const char *morpheme)
{
	new->form.value = value;
	new->form.form_type = type;
	create_form_box(new);
	add_form_buffer(new);
	if (morpheme != NULL)
		add_form_morpheme(new, morpheme);
}

t_hbranch	*add_form(t_hbranch *parent_branch, void *value, t_form_type type, const char *morpheme)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	create_form(new, value, type, morpheme);
	new->type = FORM;
	new->precompute = precompute_form;
	new->render = (void (*)(t_hbranch *, void *))render_box;
	/*
	new->precompute = precompute_form;
	new->render = (void (*)(t_hbranch *, void *))render_form;
	*/
	add_func_button_hook(new->head->mlx_data, MLCLICK, (void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_focus_form, new);
	add_func_key_hook(new->head->mlx_data, is_form_typing_key, (void (*)(void *, t_mlx *))hook_typing_form, new);
	// should instead use multiple hooks for special actions like enter and real typing
	return (new);
}
