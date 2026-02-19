/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_button_group.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:04:04 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 21:29:31 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_button_group_overlay(t_hbranch *hbranch)
{
	t_rgba_int	save_color;
	uint8_t		save_border_size;
	t_hbranch	*switched;

	if (hbranch->button_group.group_type == GROUP_DEFAULT)
		return ;
	if (hbranch->childs->num_elements <= hbranch->button_group.switched_index)
		return ;
	switched = get_hbranch_child_idx(hbranch,
			hbranch->button_group.switched_index);
	save_color = switched->box.color;
	save_border_size = switched->box.border.size;
	switched->box.color = switched->head->style.primary;
	switched->box.color.a = 120;
	switched->box.border.size = 0;
	render_box(switched, &switched->box);
	switched->box.color = save_color;
	switched->box.border.size = save_border_size;
}
