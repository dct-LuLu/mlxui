/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scrollbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:27:28 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/06 12:52:59 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"
#include "operations.h"

void	hook_scrollup_scrollbox(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_scrolldown_scrollbox(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data);

static inline t_hbranch	*create_scrollbar(t_hbranch *new)
{
	t_hbranch	*scrollbar;

	scrollbar = add_box(new,
			(t_radius){.style = FULL_PX, .full = 5},
			(t_border){0});
	if (!scrollbar)
		return (NULL);
	scrollbar->anchor = RT;
	scrollbar->size.x = 8;
	scrollbar->box.color = new->head->style.card;
	scrollbar->box.color.a = 255;
	new->scrollbox.scrollbar = scrollbar;
	return (scrollbar);
}

static inline t_hbranch	*create_scrollbox(t_hbranch *new)
{
	new->scrollbox._current_pos = 0;
	new->scrollbox.sensitivity = 5;
	new->scrollbox.inside = add_branch(new);
	if (!new->scrollbox.inside)
		return (NULL);
	new->scrollbox.inside->x_pos_operation = copy;
	new->scrollbox.inside->y_pos_operation = copy;
	new->scrollbox.inside->x_size_operation = copy;
	return (new->scrollbox.inside);
}

t_hbranch	*add_scrollbox(t_hbranch *parent_branch)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (NULL);
	new->type = SCROLLBOX;
	new->precompute = precompute_scrollbox;
	new->render = (void (*)(t_hbranch *, void *))render_clear_scrollbox;
	if (!create_scrollbox(new))
		return (NULL);
	if (!create_scrollbar(new))
		return (NULL);
	if (add_func_button_hook(new->head->mlx_data, MWHEELUP,
		(void (*)(t_vec2i, t_maction, void *, t_mlx *))
		hook_scrollup_scrollbox, new) != 0)
		return (NULL);
	if (add_func_button_hook(new->head->mlx_data, MWHEELDOWN,
		(void (*)(t_vec2i, t_maction, void *, t_mlx *))
		hook_scrolldown_scrollbox, new) != 0)
		return (NULL);
	return (new);
}
