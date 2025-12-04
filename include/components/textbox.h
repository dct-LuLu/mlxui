/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:10:07 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/04 19:36:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTBOX_H
# define TEXTBOX_H

typedef enum e_text_wrapping
{
	NO_WRAPPING,
	CHAR_WRAPPING,
	WORD_WRAPPING
}	t_text_wrapping;

typedef enum e_text_horz_align
{
	LEFT_ALIGN,
	RIGHT_ALIGN,
	CENTER_ALIGN
}	t_text_horz_align;

typedef enum e_text_vert_align
{
	MIDDLE_ALIGN,
	BASELINE_ALIGN
}	t_text_vert_align;

typedef struct s_textbox
{
	ANON_GEOM_PACKED;
	union
	{
		t_text	text;
		struct
		{
			TEXT_FIELDS;
		};
	};
	t_text_horz_align	horz_align;
	t_text_vert_align	vert_align;
	t_text_wrapping		wrapping;
	unsigned int		_newline_y;
}	t_textbox;

t_hbranch	*add_textbox(t_hbranch *parent_branch, t_text text, t_text_horz_align horz_align, t_text_wrapping wrapping);
void		precompute_textbox(t_hbranch *hbranch);
void		render_textbox(t_hbranch *hbranch, t_textbox *textbox);

#endif//TEXTBOX_H
