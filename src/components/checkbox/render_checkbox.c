/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_checkbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/21 22:11:29 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_checkbox(t_hbranch *hbranch, t_checkbox *checkbox)
{
	render_box(hbranch, &checkbox->box);
	if (checkbox->checked && *checkbox->checked)
		draw_checkmark(checkbox->_lt, hbranch->head->style.primary_fg, hbranch->img);
}
