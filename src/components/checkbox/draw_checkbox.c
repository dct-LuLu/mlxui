/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_checkbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 13:11:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkbox.h"

typedef struct s_checkbox
{
	bool	*checked;
}	t_checkbox;

static inline void	draw_checkmark(t_hbranch *hbranch, t_checkbox *checkbox)
{
	const t_vec2i	check[3] = (t_vec2i[3])
	{
		vec2i(checkbox._lt.x + 3, checkbox._lt.y + 9),
		vec2i(checkbox._lt.x + 7, checkbox._lt.y + 13),
		vec2i(checkbox._lt.x + 14, checkbox._lt.y + 6)
	};
	const t_rgb_int	white = drgb_int(0xFFFFFF);

	ft_mlx_line_put(&mlx_data->img, check[0], check[1], white);
	ft_mlx_line_put(&mlx_data->img, check[1], check[2], white);
}

void	draw_checkbox(t_hbranch *hbranch, t_checkbox *checkbox)
{
	if (hbranch->hidden)
		return ;
	draw_box(&checkbox->box);
	if (checkbox->checked && *checkbox->checked)
		draw_checkmark(hbranch, checkbox);
}

static inline void	create_checkbox(t_hbranch *new, bool hidden, bool *checked)
{
	new->checkbox = (t_checkbox)
	{
		.box = (t_box)
		{
			.size = vec2i(17, 17),
			.radius = (t_radius)
			{
				.style = FULL_PX,
				.full = 3
			},
			.border = (t_border)
			{
				.style = SOLID,
				.color = new->head->style.outline
			}
		},
		.checked = checked
	};
	if (checked && *checked)
		checkbox->color = new->head->style.accent;
	else
		checkbox->color = new->head->style.color;
	checkbox->box.border.size = (int)!(checked && *checked);
}

t_hbranch	*add_checkbox(t_hbranch *parent_branch, bool hidden, bool *checked)
{
	t_hbranch	*new;

	new = add_branch(parent_branch, hidden);
	new->type = CHECKBOX;
	create_checkbox(new, hidden, checked);
	return (new);
}

void	switch_checkbox(t_hbranch *checkbox)
{
	if (checkbox->checked)
	{
		*checkbox->checked = !*checkbox->checked;
		if (*checkbox->checked)
			checkbox->color = new->head->style.accent;
		else
			checkbox->color = new->head->style.color;
		checkbox->box.border.size = (int)!(*checkbox->checked);
	}
}
