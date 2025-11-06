/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:10:07 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/06 18:56:03 by jaubry--         ###   ########.fr       */
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

typedef enum e_text_align
{
	LEFT_ALIGN,
	RIGHT_ALIGN,
	CENTER_ALIGN
}	t_text_align;

typedef struct s_textbox
{
	ANON_GEOM_PACKED;
	union
	{
		t_text	text;
		struct {
		TEXT_FIELDS;
		};
	};
	t_text_align	align;
	t_text_wrapping	wrapping;
	unsigned int	_newline_y;
}	t_textbox;

t_hbranch	*add_textbox(t_hbranch *parent_branch, t_text text, t_text_align align, t_text_wrapping wrapping);
void		precompute_textbox(t_hbranch *hbranch);
void		render_textbox(t_hbranch *hbranch, t_textbox *textbox);

#endif//TEXTBOX_H
