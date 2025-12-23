/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:10:07 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:36:48 by jaubry--         ###   ########.fr       */
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
	struct __attribute__((packed))
	{
		t_anchor			anchor;
		struct
		{
			t_vec2i			pos;
			void			(*x_pos_operation)(size_t, t_hbranch *,
					size_t, size_t);
			void			(*y_pos_operation)(size_t, t_hbranch *,
					size_t, size_t);
		};
		struct
		{
			t_vec2i			size;
			void			(*x_size_operation)(size_t, t_hbranch *,
					size_t, size_t);
			void			(*y_size_operation)(size_t, t_hbranch *,
					size_t, size_t);
		};
		void				(*precompute)(t_hbranch *);
		void				(*render)(t_hbranch *, void *);
		t_vec2				_half_size;
		t_vec2i				_mid;
		t_vec2i				_lt;
		t_vec2i				_rt;
		t_vec2i				_lb;
		t_vec2i				_rb;
		t_img_data			*img;
		t_hbranch			*_in_scrollbox;
	};
	union
	{
		t_text				text;
		struct
		{
			char			content[MAX_CHARS];
			unsigned int	font_size;
			t_rgba_int		fg;
			t_rgb_int		bg;
			t_rgba_int		outline;
			bool			outlined;
			bool			subpixel;
			t_ttf_font		*font;
			t_vec2i			_text_pos;
			t_vec2i			_lt_limit;
			t_vec2i			_rb_limit;
			t_img_data		*_img;
		};
	};
	t_text_horz_align		horz_align;
	t_text_vert_align		vert_align;
	t_text_wrapping			wrapping;
	unsigned int			_newline_y;
}							t_textbox;

t_hbranch	*add_textbox(t_hbranch *parent_branch, t_text text,
				t_text_horz_align horz_align, t_text_wrapping wrapping);
void		precompute_textbox(t_hbranch *hbranch);
void		render_textbox(t_hbranch *hbranch, t_textbox *textbox);

#endif//TEXTBOX_H
