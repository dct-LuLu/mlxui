/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:59:30 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/14 13:25:52 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

#define MIN_CHAR "       '    ,-./01234567\
89 ; =                             [\\]  `abcdefghijklmnopqrstuvwxyz"
#define MAX_CHAR "       \"    <_>?)!@#$%^\
&*( : +                             {|}  ~ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMPAD_CHAR "7486293150.          *+ - /"

bool	is_form_typing_key(const int keycode)
{
	return (is_tkl_char_key(keycode) || is_numpad_char_key(keycode));
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

void	hook_form_typing(t_hbranch *hbranch, t_mlx *mlx_data)
{
	const size_t	edit_pos = ft_strlen(hbranch->form.edit_form_buf);
	const char		c = get_form_char_input(mlx_data->key_input.keycode,
			mlx_data->key_input.caps ^ mlx_data->key_input.shift);

	if (!hbranch->form.focused)
		return ;
	if (hbranch->form.is_valid_input(c) && (edit_pos < (FORM_BUF_SIZE - 1)))
		hbranch->form.edit_form_buf[edit_pos] = c;
	ft_strlcpy(hbranch->form.form_text->content,
		hbranch->form.edit_form_buf, FORM_BUF_SIZE);
}

void	hook_form_enter(t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if (!hbranch->form.focused)
		return ;
	hbranch->form._btov(hbranch->form.value, hbranch->form.edit_form_buf);
	hbranch->form._vtob(hbranch->form.edit_form_buf, hbranch->form.value);
	ft_strlcpy(hbranch->form.last_form_buf,
		hbranch->form.edit_form_buf, FORM_BUF_SIZE);
	switch_focus_form(hbranch, false);
	ft_strlcpy(hbranch->form.form_text->content,
		hbranch->form.edit_form_buf, FORM_BUF_SIZE);
	if (hbranch->form.action3)
		hbranch->form.action3(hbranch, hbranch->button.args3[0], hbranch->button.args3[1], hbranch->button.args3[2]);
}

void	hook_form_backspace(t_hbranch *hbranch, t_mlx *mlx_data)
{
	const size_t	edit_pos = ft_strlen(hbranch->form.edit_form_buf);

	(void)mlx_data;
	if (!hbranch->form.focused)
		return ;
	if (edit_pos > 0)
		hbranch->form.edit_form_buf[edit_pos - 1] = '\0';
	ft_strlcpy(hbranch->form.form_text->content,
		hbranch->form.edit_form_buf, FORM_BUF_SIZE);
}
