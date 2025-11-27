/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:18:05 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/27 01:50:16 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

//# define FORM_INT_INPUT "0123456789"
# define FORM_INT_INPUT "-+0123456789"
# define FORM_FLOAT_INPUT ".-+0123456789"
// this may be long for str input, maybe function first is better

# define FORM_BUF_SIZE 20
# define MORPHEME_SIZE 5

typedef enum e_form_type
{
	FORM_INT,
	FORM_FLOAT,
	FORM_STR
}	t_form_type;

typedef struct s_form
{
	union
	{
		ANON_GEOM_PACKED;
		t_box	box;
	};
	bool		focused;
	t_form_type	form_type;
	void		*value;// (STR / FLOAT / INT)
	t_textbox	*form_text;
	char		last_form_buf[FORM_BUF_SIZE];//form size need to be < to textbox size
	char		edit_form_buf[FORM_BUF_SIZE];
	t_textbox	*morpheme;
	bool		(*is_valid_input)(char c);
	void		(*format_buf)(char buffer[FORM_BUF_SIZE]);
	void		(*_btov)(void *value, const char buffer[FORM_BUF_SIZE], t_form_type type);//writes into str buf using correct type based on the value
	void		(*_vtob)(char buffer[FORM_BUF_SIZE], const void *value, t_form_type type);//writes into the value using correct type based on str buf
}	t_form;

t_hbranch	*add_form(t_hbranch *parent_branch, void *value, t_form_type type, const char *morpheme);
void		precompute_form(t_hbranch *hbranch);

void	hook_typing_form(t_hbranch *hbranch, t_mlx *mlx_data);
bool	is_form_typing_key(const int keycode);
void	switch_focus_form(t_hbranch *hbranch, bool inside);
void	hook_focus_form(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data);

bool	form_is_valid_input(char c);
void	form_format_buf(char buffer[FORM_BUF_SIZE]);
void	form_btov(void *value, const char buffer[FORM_BUF_SIZE], t_form_type type);
void	form_vtob(char buffer[FORM_BUF_SIZE], const void *value, t_form_type type);

void	form_suffix_pos_x(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);
void	form_suffix_size_x(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);
void	copy_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);
void	center_abs_parent(size_t field_offset, t_hbranch *this, size_t render_i, size_t render_num);

#endif//FORM_H

//last_form_buffer (used when exiting form while typing was made)
//edit_form_buffer (used to store text when writing into form)
//morphene_str (used to store text prefix)

/*
	HOOK (TYPING) char textbuffer[FORM_SIZE];
	FORMATER (STRING CORRECTING, AFTER ENTER or CONTEXT OUT)
	VALIDATOR (TRANSFORM STRING INTO WANTED VALUE)
*/

/*
	const char	suffix_morpheme[5];
	added after formated string and not used for centering
*/
