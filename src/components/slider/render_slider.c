/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_slider.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:54:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 06:58:45 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

static inline void	render_slider_bar(t_hbranch *hbranch, t_slider *slider)
{
	int			xpt[2];
	int			y;

	xpt[0] = slider->_bar_start.x;
	xpt[1] = slider->_bar_end.x;
	y = hbranch->_mid.y - (SLIDER_BAR_HEIGHT / 2);
	while (y < (hbranch->_mid.y + (SLIDER_BAR_HEIGHT / 2)))
	{
		ft_mlx_hline_aput(hbranch->img, xpt, y, hbranch->head->style.muted);
		y++;
	}
}

static inline void	render_slider_knob(t_hbranch *hbranch, t_slider *slider)
{
	t_rgba_int	knob_color;

	if (slider->_dragging)
		knob_color = hbranch->head->style.primary;
	else
		knob_color = hbranch->head->style.accent;
	ft_mlx_circle_aput(hbranch->img, slider->_knob_pos,
		SLIDER_KNOB_RADIUS, hbranch->head->style.accent);
	ft_mlx_out_circle_aput(hbranch->img, slider->_knob_pos,
		SLIDER_KNOB_RADIUS, knob_color);
}

void	render_slider(t_hbranch *hbranch, t_slider *slider)
{
	render_slider_bar(hbranch, slider);
	render_slider_knob(hbranch, slider);
}
