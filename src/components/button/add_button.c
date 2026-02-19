/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:54:23 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:01:56 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	create_button(t_hbranch *new,
						t_radius radius, t_border border)
{
	new->box.color = new->head->style.card;
	new->box.radius = radius;
	new->box.border = border;
}

t_hbranch	*add_button(t_hbranch *parent_branch,
				t_radius radius, t_border border)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->type = BUTTON;
	new->precompute = precompute_box;
	new->render = (t_action *)render_box;
	create_button(new, radius, border);
	new->button._event_click_idx = add_func_button_hook(new->head->mlx_data,
			MLCLICK,
			(t_button_action *)hook_click_button,
			new);
	if (new->button._event_click_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	new->button._event_move_idx = add_func_move_hook(new->head->mlx_data,
			(t_move_action *)hook_hover_button, new);
	if (new->button._event_move_idx < 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (new);
}
