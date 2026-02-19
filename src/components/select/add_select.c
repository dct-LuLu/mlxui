/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 08:27:52 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:55:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void		selected_offset_parent(size_t field_offset, t_hbranch *this,
				size_t render_i, size_t render_num);
t_hbranch	*create_expand(t_hbranch *new, char label[SELECT_LABEL_LEN]);

static inline t_hbranch	*create_select(t_hbranch *new,
							char label[SELECT_LABEL_LEN])
{
	t_hbranch	*selected;

	selected = add_textbox(new, (t_text){
			.font_size = 2,
			.fg = new->head->style.input,
		}, LEFT_ALIGN, NO_WRAPPING);
	if (!selected)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "selected textbox",
			"select");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	new->select.selected = &selected->textbox;
	selected->anchor = LT;
	selected->size = vec2i(150, 36);
	selected->x_pos_operation = selected_offset_parent;
	selected->y_pos_operation = copy_parent;
	selected->textbox.vert_align = MIDDLE_ALIGN;
	ft_strlcpy(selected->textbox.content, label, SELECT_LABEL_LEN);
	if (!create_expand(new, label))
		return (NULL);
	return (selected);
}

void		switch_select_expand(t_hbranch *hbranch, void *arg);
void		hook_click_outside_select(t_vec2i pos, t_maction action,
				t_hbranch *hbranch, t_mlx *mlx_data);

t_hbranch	*add_select(t_hbranch *parent_branch,
				char label[SELECT_LABEL_LEN])
{
	t_hbranch	*new;

	new = add_button(parent_branch, (t_radius){.style = FULL_PX, .full = 9},
			(t_border){.size = 1, .color
			= parent_branch->head->style.border, .style = SOLID});
	if (!new)
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "display button",
			"select");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	new->type = SELECT;
	new->render = (void (*)(t_hbranch *, void *))render_select;
	new->select.button.box.size = vec2i(200, 36);
	new->select.button.action = switch_select_expand;
	new->select._event_click_idx = add_func_button_hook(new->head->mlx_data,
			MLCLICK, (t_button_action *)hook_click_outside_select, new);
	if (new->select._event_click_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (!create_select(new, label))
		return (NULL);
	return (new);
}
