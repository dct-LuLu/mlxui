/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_select_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:37:12 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/06 13:17:42 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	selected_offset_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);

int	add_select_option(t_hbranch *select, char option_name[SELECT_LABEL_LEN],
		void (*option_action)(t_hbranch *hbranch, void *arg))
{
	t_hbranch	*option;
	t_hbranch	*option_label;

	option = add_button(select->select.margin, (t_radius){.style = FULL_PX, .full = 9}, (t_border){});
	option->size = vec2i(196, 36);
	option->anchor = LT;
	option->x_pos_operation = copy_parent;
	if (select->select.options->num_elements == 0)
		option->y_pos_operation = copy_parent;
	option->button.action = option_action;
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
