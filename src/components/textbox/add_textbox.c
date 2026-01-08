/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textbox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:26:31 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:42:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	create_textbox(t_hbranch *new, t_text text,
		t_text_horz_align horz_align, t_text_wrapping wrapping)
{
	new->textbox.text = text;
	new->textbox.horz_align = horz_align;
	new->textbox.wrapping = wrapping;
	new->textbox.font = new->head->style.font;
	if (new->textbox.fg.rgba == 0)
		new->textbox.fg = new->head->style.foreground;
	if ((new->textbox.bg.rgb == 0) && new->textbox.subpixel
		&& (new->parent->type == BOX))
		new->textbox.bg.rgb = new->parent->box.color.rgba;
	new->textbox._img = new->img;
}

t_hbranch	*add_textbox(t_hbranch *parent_branch, t_text text,
				t_text_horz_align horz_align, t_text_wrapping wrapping)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	create_textbox(new, text, horz_align, wrapping);
	new->type = TEXTBOX;
	new->precompute = precompute_textbox;
	new->render = (void (*)(t_hbranch *, void *))render_textbox;
	return (new);
}
