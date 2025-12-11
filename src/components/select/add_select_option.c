/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_select_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:37:12 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/11 07:45:44 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

typedef void (*t_option_action)(t_hbranch *hbranch, void *arg);

void	selected_offset_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);
void	option_offset(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);
void	switch_select_expand(t_hbranch *hbranch, void *arg);

void	select_option_wrapper(t_hbranch *hbranch, void *arg)
{
	t_select		*select;
	t_option_action	*option_action;
	size_t			clicked_index;

	select = &hbranch->parent->parent->parent->parent->select;
	clicked_index = get_vector_index(hbranch->parent->childs, hbranch) + 1;
	if (clicked_index == select->option_index && select->nullable)
	{
		select->option_index = 0;
		ft_strlcpy(select->selected->content, ((t_hbranch *)(get_vector_value(select->label_box->childs, 0)))->textbox.content, SELECT_LABEL_LEN);
		switch_select_expand(hbranch->parent->parent->parent->parent, NULL);
	}
	else
	{
		select->option_index = clicked_index;
		ft_strlcpy(select->selected->content, ((t_hbranch *)(get_vector_value(hbranch->childs, 0)))->textbox.content, SELECT_LABEL_LEN);
		switch_select_expand(hbranch->parent->parent->parent->parent, NULL);
		option_action = get_vector_value(select->actions, select->option_index - 1);
		(*option_action)(hbranch, arg);
	}
}

int	add_select_option(t_hbranch *select, char option_name[SELECT_LABEL_LEN],
		void (*option_action)(t_hbranch *hbranch, void *arg))
{
	t_hbranch	*option;
	t_hbranch	*option_label;

	if (select->select.options->num_elements >= MAX_OPTIONS)
		return (1);
	if ((select->select.options->num_elements == 0) && !select->select.nullable)
	{
		ft_strlcpy(select->select.selected->content, option_name, SELECT_LABEL_LEN);
		select->select.option_index = 1;
	}
	option = add_button(select->select.margin, (t_radius){.style = FULL_PX, .full = 11}, (t_border){});
	select->select.margin->box.size.y += 36;
	select->select.expand->size.y += 36;
	option->size = vec2i(192, 36);
	option->anchor = LT;
	option->x_pos_operation = copy_parent;
	option->y_pos_operation = option_offset;
	if (select->select.actions == NULL)
	{
		select->select.actions = ft_calloc(sizeof(t_vector), 1);
		vector_init(select->select.actions, sizeof(t_option_action));
	}
	if (vector_add(select->select.actions, &option_action, 1) != 0)
		return (1);
	option->button.action = select_option_wrapper;
	option_label = add_textbox(option,
			(t_text)
			{
				.font_size = 2,
				.fg = select->head->style.input,
			}, LEFT_ALIGN, NO_WRAPPING);
	option_label->anchor = LT;
	option_label->size = vec2i(150, 36);
	option_label->x_pos_operation = selected_offset_parent;
	option_label->y_pos_operation = copy_parent;
	option_label->textbox.vert_align = MIDDLE_ALIGN;
	ft_strlcpy(option_label->textbox.content, option_name, SELECT_LABEL_LEN);
	return (0);
}
