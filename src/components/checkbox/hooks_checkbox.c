/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_checkbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:39:16 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:04:17 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	switch_checkbox(t_hbranch *hbranch)
{
	if (hbranch->checkbox.checked)
	{
		*hbranch->checkbox.checked = !*hbranch->checkbox.checked;
		if (*hbranch->checkbox.checked)
			hbranch->checkbox.box.color = hbranch->head->style.primary;
		else
			hbranch->checkbox.box.color = hbranch->head->style.input;
		hbranch->checkbox.box.border.size
			= (int)(!(*hbranch->checkbox.checked));
	}
}

void	hook_checkbox(t_vec2i pos, t_maction action,
		t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && is_inside_comp(hbranch, pos)
		&& hbranch->rendered && hbranch->visible)
		switch_checkbox(hbranch);
}
