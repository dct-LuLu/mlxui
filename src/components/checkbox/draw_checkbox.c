/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_checkbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/30 18:20:49 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkbox.h"

typedef struct s_checkbox
{
	bool	*checked;
}	t_checkbox;

void	draw_checkbox(t_hbranch *hbranch, t_checkbox *checkbox)
{
	if (hbranch->hidden)
		return ;
	draw_box(&checkbox->box);
	if (checkbox->checked)
	{

	}
}

int	create_checkbox(t_checkbox *checkbox)
{
	*checkbox = (t_checkbox)
	{
		.checked = false,
		.box = (t_box)
		{
			
		}
	}
}
