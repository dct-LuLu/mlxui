/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_checkbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:25:41 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:04:29 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	create_checkbox(t_hbranch *new, bool *checked)
{
	new->checkbox.box.size = vec2i(17, 17);
	new->checkbox.box.radius.style = FULL_PX;
	new->checkbox.box.radius.full = 3;
	new->checkbox.box.border.style = SOLID;
	new->checkbox.box.border.color = new->head->style.border;
	new->checkbox.checked = checked;
	if (checked && *checked)
		new->checkbox.box.color = new->head->style.primary;
	else
		new->checkbox.box.color = new->head->style.input;
	new->checkbox.box.border.size = (int)(!(checked && *checked));
}

t_hbranch	*add_checkbox(t_hbranch *parent_branch, bool *checked)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	new->type = CHECKBOX;
	new->precompute = precompute_checkbox;
	new->render = (void (*)(t_hbranch *, void *))render_checkbox;
	create_checkbox(new, checked);
	add_func_button_hook(new->head->mlx_data, MLCLICK,
		(void (*)(t_vec2i, t_maction, void *, t_mlx *))hook_checkbox, new);
	return (new);
}
