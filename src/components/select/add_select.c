/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 08:27:52 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:41:39 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	selected_offset_parent(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	margin_offset_parent(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	entry_offset(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	expanded_offset(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);

static inline t_hbranch	*create_expand_label(t_hbranch *new,
		char label[SELECT_LABEL_LEN])
{
	t_hbranch	*label_box;
	t_hbranch	*label_text;

	label_box = add_box(new, (t_radius){.style = LOCAL_PX, .lt = 9, .rt = 9},
			(t_border){.size = 1, .color = new->head->style.border,
			.style = SOLID});
	label_box->box.size = vec2i(200, 36);
	label_box->x_pos_operation = copy_parent;
	label_box->y_pos_operation = expanded_offset;
	label_box->anchor = LT;
	label_box->rendered = false;
	new->select.label_box = label_box;
	label_text = add_textbox(label_box, (t_text){.font_size = 2,
			.fg = new->head->style.input}, LEFT_ALIGN, NO_WRAPPING);
	label_text->textbox.text.fg.a = 5;
	label_text->anchor = LT;
	label_text->size = vec2i(180, 36);
	label_text->x_pos_operation = selected_offset_parent;
	label_text->y_pos_operation = copy_parent;
	label_text->textbox.vert_align = MIDDLE_ALIGN;
	ft_strlcpy(label_text->textbox.content, label, SELECT_LABEL_LEN);
	return (label_box);
}

static inline void	create_expand(t_hbranch *new, char label[SELECT_LABEL_LEN])
{
	t_hbranch	*expand_box;
	t_hbranch	*margin;
	t_hbranch	*label_box;

	label_box = create_expand_label(new, label);
	expand_box = add_box(label_box, (t_radius){.style = LOCAL_PX,
			.lb = 9, .rb = 9}, (t_border){.size = 1, .color
			= new->head->style.border, .style = SOLID});
	expand_box->x_pos_operation = copy_parent;
	expand_box->y_pos_operation = entry_offset;
	expand_box->box.pos = label_box->_lb;
	expand_box->box.size = vec2i(200, 8);
	expand_box->anchor = LT;
	new->select.expand = expand_box;
	margin = add_box(expand_box, (t_radius){}, (t_border){});
	margin->box.size = vec2i(192, 0);
	margin->x_pos_operation = margin_offset_parent;
	margin->y_pos_operation = margin_offset_parent;
	margin->anchor = LT;
	new->select.margin = margin;
	new->select.options = margin->childs;
}

static inline void	create_select(t_hbranch *new, char label[SELECT_LABEL_LEN])
{
	t_hbranch	*selected;

	selected = add_textbox(new, (t_text){
			.font_size = 2,
			.fg = new->head->style.input,
		}, LEFT_ALIGN, NO_WRAPPING);
	new->select.selected = &selected->textbox;
	selected->anchor = LT;
	selected->size = vec2i(150, 36);
	selected->x_pos_operation = selected_offset_parent;
	selected->y_pos_operation = copy_parent;
	selected->textbox.vert_align = MIDDLE_ALIGN;
	ft_strlcpy(selected->textbox.content, label, SELECT_LABEL_LEN);
	create_expand(new, label);
}

void	switch_select_expand(t_hbranch *hbranch, void *arg);
void	hook_click_outside_select(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data);

t_hbranch	*add_select(t_hbranch *parent_branch, char label[SELECT_LABEL_LEN])
{
	t_hbranch	*new;

	new = add_button(parent_branch, (t_radius){.style = FULL_PX, .full = 9},
			(t_border){.size = 1, .color
			= parent_branch->head->style.border, .style = SOLID});
	new->type = SELECT;
	new->render = (void (*)(t_hbranch *, void *))render_select;
	new->select.button.box.size = vec2i(200, 36);
	new->select.button.action = switch_select_expand;
	add_func_button_hook(new->head->mlx_data, MLCLICK,
		(void (*)(t_vec2i, t_maction, void *, t_mlx *))
		hook_click_outside_select, new);
	create_select(new, label);
	return (new);
}
