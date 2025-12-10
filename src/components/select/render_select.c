/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:03:24 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/10 13:36:00 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_select(t_hbranch *hbranch, t_select *select)
{
	t_vec2i	arrow_pos;

	render_box(hbranch, &select->button.box);
	arrow_pos = vec2i(select->_rb.x - 17 - 12, select->_rb.y - 17 - 9);
	draw_down_arrow(arrow_pos, hbranch->head->style.input, hbranch->head->mlx_data);
}

void	render_select_special(t_hbranch *hbranch, t_select *select)
{
	t_vec2i	checkmark_pos;
	t_hbranch	*selected;

	if (select->expanded && select->option_index)
	{
		selected = get_vector_value(select->margin->childs, select->option_index - 1);
		checkmark_pos = vec2i(selected->_rb.x - 17 - 12, selected->_rb.y - 17 - 9);
		draw_checkmark(checkmark_pos, hbranch->head->style.input, hbranch->head->mlx_data);
	}
}
