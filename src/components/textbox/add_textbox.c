/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textbox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:26:31 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/06 18:44:34 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	create_textbox(t_hbranch *new, t_text text, t_text_align align, t_text_wrapping wrapping)
{
	new->textbox.text = text;
	new->textbox.align = align;
	new->textbox.wrapping = wrapping;
	//if (!new->textbox.font)
	//{
	//new->textbox.font = ft_calloc(sizeof(t_ttf_font), 1);
	//ft_memcpy(new->textbox.font, new->head->style.font, sizeof(t_ttf_font));
	new->textbox.font = new->head->style.font;
	//printf("%p\n", new->textbox.font);
	//printf("%p\n", new->head->style.font);
	printf("2 %p\n", new->textbox.font->head);
	//}
	//new->textbox.font = new->head->style.font;
	if (new->textbox.fg.rgba == 0)
		new->textbox.fg = new->head->style.text_fg;
	if ((new->textbox.bg.rgb == 0) && new->textbox.subpixel && (new->parent->type == BOX))
		new->textbox.bg.rgb = new->parent->box.color.rgba;
	printf("feur %p\n", new->textbox.font->head);
	new->textbox._img = &new->head->mlx_data->img;
	printf("feur %p\n", new->textbox.font->head);
}

t_hbranch	*add_textbox(t_hbranch *parent_branch, t_text text, t_text_align align, t_text_wrapping  wrapping)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	create_textbox(new, text, align, wrapping);
	new->type = TEXTBOX;
	new->precompute = precompute_textbox;
	new->render = (void (*)(t_hbranch *, void *))render_textbox;
	return (new);
}
