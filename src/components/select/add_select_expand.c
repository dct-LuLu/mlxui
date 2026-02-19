/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_select_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:49:10 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:58:13 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxui.h"

void	selected_offset_parent(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	margin_offset_parent(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	entry_offset(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	expanded_offset(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);

static inline t_hbranch	*create_expand_label_text(t_hbranch *label_box,
		t_hbranch *new, char label[SELECT_LABEL_LEN])
{
	t_hbranch	*label_text;

	label_text = add_textbox(label_box, (t_text){.font_size = 2,
			.fg = new->head->style.input}, LEFT_ALIGN, NO_WRAPPING);
	if (!label_text)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "expand label", "select");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	label_text->textbox.text.fg.a = 5;
	label_text->anchor = LT;
	label_text->size = vec2i(180, 36);
	label_text->x_pos_operation = selected_offset_parent;
	label_text->y_pos_operation = copy_parent;
	label_text->textbox.vert_align = MIDDLE_ALIGN;
	ft_strlcpy(label_text->textbox.content, label, SELECT_LABEL_LEN);
	return (label_box);
}

static inline t_hbranch	*create_expand_label(t_hbranch *new,
		char label[SELECT_LABEL_LEN])
{
	t_hbranch	*label_box;

	label_box = add_box(new, (t_radius){.style = LOCAL_PX, .lt = 9, .rt = 9},
			(t_border){.size = 1, .color = new->head->style.border,
			.style = SOLID});
	if (!label_box)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "expand label box",
			"select");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	label_box->box.size = vec2i(200, 36);
	label_box->x_pos_operation = copy_parent;
	label_box->y_pos_operation = expanded_offset;
	label_box->anchor = LT;
	label_box->rendered = false;
	new->select.label_box = label_box;
	return (create_expand_label_text(label_box, new, label));
}

static inline t_hbranch	*create_expand_margin(t_hbranch *expand_box,
							t_hbranch *new)
{
	t_hbranch	*margin;

	margin = add_box(expand_box, (t_radius){}, (t_border){});
	if (!margin)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "expand margin box",
			"select");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	margin->box.size = vec2i(192, 0);
	margin->x_pos_operation = margin_offset_parent;
	margin->y_pos_operation = margin_offset_parent;
	margin->anchor = LT;
	new->select.margin = margin;
	new->select.options = margin->childs;
	return (margin);
}

t_hbranch	*create_expand(t_hbranch *new, char label[SELECT_LABEL_LEN])
{
	t_hbranch	*expand_box;
	t_hbranch	*label_box;

	label_box = create_expand_label(new, label);
	if (!label_box)
		return (NULL);
	expand_box = add_box(label_box, (t_radius){.style = LOCAL_PX,
			.lb = 9, .rb = 9}, (t_border){.size = 1, .color
			= new->head->style.border, .style = SOLID});
	if (!expand_box)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "expand box", "select");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	expand_box->x_pos_operation = copy_parent;
	expand_box->y_pos_operation = entry_offset;
	expand_box->box.pos = label_box->_lb;
	expand_box->box.size = vec2i(200, 8);
	expand_box->anchor = LT;
	new->select.expand = expand_box;
	return (create_expand_margin(expand_box, new));
}
