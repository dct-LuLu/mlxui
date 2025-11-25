/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_form.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:47:15 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/25 21:57:01 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	precompute_form(t_hbranch *hbranch)
{
	precompute_box(hbranch);
	hbranch->form._vtob(hbranch->form.last_form_buf, hbranch->form.value, hbranch->form.form_type);
	ft_strlcpy(hbranch->form.edit_form_buf, hbranch->form.last_form_buf, FORM_BUF_SIZE);
	ft_strlcpy(hbranch->form.form_text->content, hbranch->form.last_form_buf, FORM_BUF_SIZE);
	hbranch->form.format_buf(hbranch->form.form_text->content);
}
