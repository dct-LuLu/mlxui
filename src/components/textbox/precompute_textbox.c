/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_textbox.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:26:52 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/04 21:44:15 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	precompute_textbox(t_hbranch *hbranch)
{
	hbranch->textbox._text_pos = hbranch->textbox._lt;
	if (hbranch->textbox.vert_align == MIDDLE_ALIGN)
	{
		hbranch->textbox._text_pos.y += hbranch->_half_size.y;
		hbranch->textbox._text_pos.y += measure_line_height(&hbranch->textbox.text) / 4;
	}
	else if (hbranch->textbox.vert_align == BASELINE_ALIGN)
		hbranch->textbox._text_pos.y += hbranch->textbox.font_size * 6;
	if ((hbranch->textbox._lt.x != hbranch->textbox._rb.x)
			&& (hbranch->textbox._lt.y != hbranch->textbox._rb.y))
	{
		hbranch->textbox._lt_limit = hbranch->textbox._lt;
		hbranch->textbox._rb_limit = hbranch->textbox._rb;
	}
	hbranch->textbox._newline_y = scale_y(&hbranch->textbox.text, 0,
		abs(hbranch->textbox.font->head->y_min) + hbranch->textbox.font->head->y_max);
}
