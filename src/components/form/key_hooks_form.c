/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:59:30 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 22:09:48 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

#define MIN_CHAR "       '    ,-./01234567\
89 ; =                             [\\]  `abcdefghijklmnopqrstuvwxyz"
#define MAX_CHAR "       \"    <_>?)!@#$%^\
&*( : +                             {|}  ~ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMPAD_CHAR "7486293150.          *+ - /"

// to move to mlx_wrapper
static inline bool	is_backspace_key(const int keycode)
{
	return (keycode == XK_BackSpace);
}

bool	is_form_typing_key(const int keycode)
{
	return (is_tkl_char_key(keycode) || is_numpad_char_key(keycode)
		|| is_enter_key(keycode) || is_backspace_key(keycode));
}

static inline char	get_form_char_input(int keycode, bool maj)
{
	char	c;

	c = '\0';
	if (is_char_key(keycode))
	{
		if (is_tkl_char_key(keycode))
		{
			if (maj)
				c = MAX_CHAR[keycode - ' '];
			else
				c = MIN_CHAR[keycode - ' '];
		}
		else if (is_numpad_char_key(keycode))
			c = NUMPAD_CHAR[keycode - 0xff95];
	}
	return (c);
}

static inline void	handle_typing_form(t_hbranch *hbranch, t_mlx *mlx_data)
{
	const size_t	edit_pos = ft_strlen(hbranch->form.edit_form_buf);
	char			c;

	if (is_backspace_key(mlx_data->key_input.keycode))
	{
		if (edit_pos > 0)
			hbranch->form.edit_form_buf[edit_pos - 1] = '\0';
	}
	else
	{
		c = get_form_char_input(mlx_data->key_input.keycode,
				mlx_data->key_input.caps ^ mlx_data->key_input.shift);
		if (hbranch->form.is_valid_input(c)
			&& (edit_pos < (FORM_BUF_SIZE - 1)))
			hbranch->form.edit_form_buf[edit_pos] = c;
	}
}

void	hook_typing_form(t_hbranch *hbranch, t_mlx *mlx_data)
{
	if (!hbranch->form.focused)
		return ;
	if (is_enter_key(mlx_data->key_input.keycode))
	{
		hbranch->form._btov(hbranch->form.value,
			hbranch->form.edit_form_buf, hbranch->form.form_type);
		hbranch->form._vtob(hbranch->form.edit_form_buf,
			hbranch->form.value, hbranch->form.form_type);
		ft_strlcpy(hbranch->form.last_form_buf,
			hbranch->form.edit_form_buf, FORM_BUF_SIZE);
		switch_focus_form(hbranch, false);
	}
	else
		handle_typing_form(hbranch, mlx_data);
	ft_strlcpy(hbranch->form.form_text->content,
		hbranch->form.edit_form_buf, FORM_BUF_SIZE);
}
