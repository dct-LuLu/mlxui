/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_scrollbox.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:34:13 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:17:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	precompute_scrollbar(t_hbranch *hbranch);
void	precompute_hbranch(t_hbranch *hbranch);

static inline void	update_scrollbar(t_hbranch *hbranch)
{
	hbranch->scrollbox.scrollbar->pos.y = hbranch->_rt.y
		+ ((float)hbranch->scrollbox._current_pos
			/ (float)hbranch->scrollbox.inside->size.y)
		* (float)hbranch->size.y;
	precompute_geometry(hbranch->scrollbox.scrollbar, 1, 2);
	precompute_box(hbranch->scrollbox.scrollbar);
}

void	hook_scrollup_scrollbox(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && hbranch->visible
		&& is_inside_comp(hbranch, pos))
	{
		hbranch->scrollbox._current_pos += hbranch->scrollbox.sensitivity;
		if (hbranch->scrollbox._current_pos
			> (hbranch->scrollbox._scroll_buffer.height - hbranch->size.y))
			hbranch->scrollbox._current_pos
				= hbranch->scrollbox._scroll_buffer.height - hbranch->size.y;
		update_scrollbar(hbranch);
	}
}

void	hook_scrolldown_scrollbox(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && hbranch->visible && is_inside_comp(hbranch, pos))
	{
		hbranch->scrollbox._current_pos -= hbranch->scrollbox.sensitivity;
		if (hbranch->scrollbox._current_pos < 0)
			hbranch->scrollbox._current_pos = 0;
		update_scrollbar(hbranch);
	}
}
