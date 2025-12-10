/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:48:37 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/10 11:02:03 by jaubry--         ###   ########.fr       */
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

void	hook_click_button(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && is_rendered(hbranch) && hbranch->visible
			&& (((pos.x > hbranch->_lt.x) && (pos.x < hbranch->_rt.x))
				&& ((pos.y > hbranch->_lt.y) && (pos.y < hbranch->_lb.y))))
	{
			hbranch->button.action(hbranch, hbranch->button.arg);
			if (hbranch->parent && (hbranch->parent->type == BUTTON_GROUP))
				hbranch->parent->button_group.switched_index = get_vector_index(hbranch->parent->childs, hbranch);
	}
}

void	hook_hover_button(t_hbranch *hbranch, t_mlx *mlx_data)
{
	const t_vec2i	pos = mlx_data->mouse_input.pos;
	const bool		hover = hbranch->button.hover;
	const bool		inside = (((pos.x > hbranch->_lt.x) && (pos.x < hbranch->_rt.x))
			&& ((pos.y > hbranch->_lt.y) && (pos.y < hbranch->_lb.y)));

	if (hover && !inside)
		hbranch->button.hover = false;
	else if (!hover && inside)
		hbranch->button.hover = true;
}
