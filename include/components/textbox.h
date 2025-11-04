/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:10:07 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/04 13:10:32 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTBOX_H
# define TEXTBOX_H

typedef enum e_text_wrapping
{
	NO_WRAPPING,
	CHAR_WRAPPING,
	WORD_WRAPPING
}	t_text_wrapping

typedef struct s_textbox
{
	ANON_GEOM_PACKED;
	char		*content;
	t_ttf_font	*font;
	uint8_t		font_size;
	t_rgba_int	fg;
	t_rgb_int	bg;
	bool		outlined;
	t_rgba_int	outline;
	bool		subpixel;
}	t_textbox;

#endif//TEXTBOX_H
