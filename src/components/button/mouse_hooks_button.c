/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:48:37 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 14:02:08 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline bool	is_rendered(t_hbranch *el)
{
	if (!el->rendered)
		return (false);
	if (el->parent)
		return (is_rendered(el->parent));
	return (true);
}

void	hook_click_button(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && is_rendered(hbranch)
		&& hbranch->visible && is_inside_comp(hbranch, pos))
	{
		if (hbranch->button.action3)
			hbranch->button.action3(hbranch, hbranch->button.args3[0], hbranch->button.args3[1], hbranch->button.args3[2]);
		if (hbranch->parent && (hbranch->parent->type == BUTTON_GROUP))
			hbranch->parent->button_group.switched_index
				= get_hbranch_index(hbranch->parent->childs, hbranch);
	}
}

void	hook_hover_button(t_hbranch *hbranch, t_mlx *mlx_data)
{
	const bool		hover = hbranch->button.hover;
	const bool		inside = is_inside_comp(hbranch, mlx_data->mouse_input.pos);

	if (hover && !inside)
		hbranch->button.hover = false;
	else if (!hover && inside)
		hbranch->button.hover = true;
}
