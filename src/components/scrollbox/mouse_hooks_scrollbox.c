/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_scrollbox.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:34:13 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/22 02:06:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	hook_scrollup_scrollbox(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && hbranch->visible
			&& (((pos.x > hbranch->_lt.x) && (pos.x < hbranch->_rt.x))
				&& ((pos.y > hbranch->_lt.y) && (pos.y < hbranch->_lb.y))))
	{
		if (hbranch->scrollbox._current_pos < (hbranch->scrollbox._scroll_buffer.height - hbranch->size.y))
			hbranch->scrollbox._current_pos++;
	}
}

void	hook_scrolldown_scrollbox(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && hbranch->visible
			&& (((pos.x > hbranch->_lt.x) && (pos.x < hbranch->_rt.x))
				&& ((pos.y > hbranch->_lt.y) && (pos.y < hbranch->_lb.y))))
	{
		if (hbranch->scrollbox._current_pos > 0)
			hbranch->scrollbox._current_pos--;

	}
}
