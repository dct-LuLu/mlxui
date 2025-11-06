/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_textbox.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:26:52 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/06 16:40:53 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	precompute_textbox(t_hbranch *hbranch)
{
	hbranch->textbox._text_pos = hbranch->textbox._lt;
	hbranch->textbox._text_pos.y += hbranch->textbox.font_size * 6;
	hbranch->textbox._lt_limit = hbranch->textbox._lt;
	hbranch->textbox._rb_limit = hbranch->textbox._rb;
	printf("%p\n", hbranch->textbox.font->head);
	hbranch->textbox._newline_y = scale_y(&hbranch->textbox.text, 0,
		abs(hbranch->textbox.font->head->y_min) + hbranch->textbox.font->head->y_max);
}
