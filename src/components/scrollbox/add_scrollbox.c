/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scrollbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:27:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/22 02:14:24 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"
#include "operations.h"

void	hook_scrollup_scrollbox(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_scrolldown_scrollbox(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data);

static inline void	create_scrollbox(t_hbranch *new)
{
	new->scrollbox._current_pos = 0;
	new->scrollbox.inside = add_branch(new);
	new->scrollbox.inside->x_pos_operation = copy;
	new->scrollbox.inside->y_pos_operation = copy;
	new->scrollbox.inside->x_size_operation = copy;
	precompute_geometry(new->scrollbox.inside, 1, 0);
}

t_hbranch	*add_scrollbox(t_hbranch *parent_branch)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	new->type = SCROLLBOX;
	new->precompute = precompute_scrollbox;
	new->render = (void (*)(t_hbranch *, void *))render_clear_scrollbox;
	create_scrollbox(new);
	add_func_button_hook(new->head->mlx_data, MWHEELUP, (void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_scrollup_scrollbox, new);
	add_func_button_hook(new->head->mlx_data, MWHEELDOWN, (void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_scrolldown_scrollbox, new);
	return (new);
}
