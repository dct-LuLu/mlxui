/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:18:21 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/21 22:15:16 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline bool	need_wrapping(t_textbox *textbox, t_vec2i pen_pos, int char_width)
{
	if ((textbox->wrapping == CHAR_WRAPPING) 
			&& ((pen_pos.x + char_width) >= textbox->_rt.x))
			return (true);
	//else if (WORD_WRAPPING)
	//	return (true);
	return (false);
}

static inline t_vec2i	get_new_pen_pos(t_textbox *textbox, t_vec2i pen_pos, char *str, bool newline)
{
	const int	newline_y = pen_pos.y - (newline * textbox->_newline_y);
	int			line_width;

	if (textbox->horz_align == LEFT_ALIGN)
		return (vec2i(textbox->_lt.x, newline_y));
	line_width = 0;
	if (str)
		line_width = measure_text_line_width(str, &textbox->text);
	if (textbox->horz_align == RIGHT_ALIGN)
		return (vec2i(textbox->_rb.x - line_width, newline_y));
	if (textbox->horz_align == CENTER_ALIGN)
		return (vec2i(textbox->_lt.x + textbox->_half_size.x - (line_width / 2),
					newline_y));
	return (vec2i(0, 0));
}

t_contour	get_contour(t_text *text, char c);
void		draw_glyph(t_contour *contour);

void	render_textbox(t_hbranch *hbranch, t_textbox *textbox)
{
	t_contour	ctr;
	t_vec2i		pen_pos;
	int			char_width;
	size_t		i;

	i = 0;
	if (DEBUG)
		ft_mlx_select_put(hbranch->img, hbranch->textbox._lt, hbranch->textbox._rb, drgb_int(0xFFFFFF));
	//pen_pos = get_new_pen_pos(&hbranch->textbox, textbox->_text_pos, textbox->content);
	pen_pos = get_new_pen_pos(&hbranch->textbox, textbox->_text_pos, textbox->content, false);
	while (textbox->content[i])
	{
		char_width = measure_char_width(textbox->content[i], &textbox->text);
		if ((textbox->content[i] == '\n') || need_wrapping(textbox, pen_pos, char_width))
			pen_pos = get_new_pen_pos(textbox, pen_pos, textbox->content + i + 1, true);
		else
		{
			ft_bzero(&ctr, sizeof(ctr));
			ctr = get_contour(&textbox->text, textbox->content[i]);
			ctr.pos = pen_pos;
			if (ctr.glyf)
				draw_glyph(&ctr);
			pen_pos.x += char_width;
		}
		i++;
	}
}
