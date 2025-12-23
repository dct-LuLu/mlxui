/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:54:23 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:55:13 by jaubry--         ###   ########.fr       */
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
	new->type = BUTTON;
	new->precompute = precompute_box;
	new->render = (void (*)(t_hbranch *, void *))render_box;
	create_button(new, radius, border);
	add_func_button_hook(new->head->mlx_data, MLCLICK,
		(void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_click_button, new);
	add_func_move_hook(new->head->mlx_data,
		(void (*)(void *, t_mlx *))hook_hover_button, new);
	return (new);
}
