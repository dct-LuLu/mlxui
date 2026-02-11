/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:27:33 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 12:40:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	switch_morpheme(t_hbranch *morpheme, bool focused)
{
	morpheme->visible = !focused;
	precompute_geometry(morpheme, 1, 2);
	morpheme->precompute(morpheme);
}

static inline void	form_in_focus_changes(t_hbranch *hbranch)
{
	ft_bzero(hbranch->form.form_text->content, FORM_BUF_SIZE);
	ft_strlcpy(hbranch->form.form_text->content,
		hbranch->form.last_form_buf, FORM_BUF_SIZE);
	hbranch->form.box.border.color = hbranch->head->style.primary;
}

static inline void	form_out_focus_changes(t_hbranch *hbranch)
{
	ft_bzero(hbranch->form.edit_form_buf, FORM_BUF_SIZE);
	ft_strlcpy(hbranch->form.edit_form_buf,
		hbranch->form.last_form_buf, FORM_BUF_SIZE);
	hbranch->form.format_buf(hbranch->form.form_text->content);
	ft_bzero(hbranch->form.form_text->content, FORM_BUF_SIZE);
	ft_strlcpy(hbranch->form.form_text->content,
		hbranch->form.last_form_buf, FORM_BUF_SIZE);
	hbranch->form.format_buf(hbranch->form.form_text->content);
	hbranch->form.box.border.color = hbranch->head->style.border;
}

void	switch_focus_form(t_hbranch *hbranch, bool inside)
{
	if (inside == hbranch->form.focused)
		return ;
	hbranch->form.focused = inside;
	if (hbranch->form.focused)
		form_in_focus_changes(hbranch);
	else
		form_out_focus_changes(hbranch);
	if (hbranch->form.morpheme)
		switch_morpheme(get_hbranch_child_idx(hbranch, 1),
			hbranch->form.focused);
}

void	hook_focus_form(t_vec2i pos, t_maction action,
		t_hbranch *hbranch, t_mlx *mlx_data)
{
	(void)mlx_data;
	if ((action == MPRESS) && hbranch->rendered && hbranch->visible)
		switch_focus_form(hbranch, is_inside_comp(hbranch, pos));
}
