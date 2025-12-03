/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:21:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/03 19:44:46 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_button_hover(t_hbranch *hbranch)
{
	t_rgba_int	save_color;
	uint8_t		save_border_size;

	save_color = hbranch->box.color;
	save_border_size = hbranch->box.border.size;
	hbranch->box.color = hbranch->head->style.input;
	hbranch->box.border.size = 0;
	render_box(hbranch, &hbranch->box);
	hbranch->box.color = save_color;
	hbranch->box.border.size = save_border_size;
}
