/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scrollbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:27:28 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/13 01:07:02 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"
#include "operations.h"

#define SCROLLBAR_WIDTH 7
#define SCROLLBAR_OPACITY 220
#define DEFAULT_SENSITIVITY 10

void	hook_scrollup_scrollbox(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data);
void	hook_scrolldown_scrollbox(t_vec2i pos, t_maction action,
			t_hbranch *hbranch, t_mlx *mlx_data);

static inline t_hbranch	*create_scrollbar(t_hbranch *new)
{
	t_hbranch	*scrollbar;

	scrollbar = add_box(new,
			(t_radius){.style = FULL_PX, .full = 4},
			(t_border){0});
	if (!scrollbar)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_COMP), FL, LN, FC));
	scrollbar->anchor = RT;
	scrollbar->size.x = SCROLLBAR_WIDTH;
	scrollbar->box.color = new->head->style.border;
	scrollbar->box.color.a = SCROLLBAR_OPACITY;
	new->scrollbox.scrollbar = scrollbar;
	return (scrollbar);
}

static inline t_hbranch	*create_scrollbox(t_hbranch *new)
{
	new->scrollbox._hook_mwheeldown = (void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_scrolldown_scrollbox;
	new->scrollbox._hook_mwheelup = (void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_scrollup_scrollbox;
	new->scrollbox._current_pos = 0;
	new->scrollbox.sensitivity = DEFAULT_SENSITIVITY;
	new->scrollbox.inside = add_box(new, (t_radius){0}, (t_border){0});
	if (!new->scrollbox.inside)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->scrollbox.inside->anchor = LT;
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
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->type = SCROLLBOX;
	new->precompute = precompute_scrollbox;
	new->render = (void (*)(t_hbranch *, void *))render_clear_scrollbox;
	if (!create_scrollbox(new))
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "inner box", "scrollbox");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	if (!create_scrollbar(new))
	{
		register_complex_err_msg(MLXUI_E_MSG_FSCOMP, "scrollbar", "scrollbox");
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FSCOMP), FL, LN, FC));
	}
	if (add_func_button_hook(new->head->mlx_data, MWHEELUP,
		new->scrollbox._hook_mwheelup, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_button_hook(new->head->mlx_data, MWHEELDOWN,
		new->scrollbox._hook_mwheeldown, new) != 0)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (new);
}
