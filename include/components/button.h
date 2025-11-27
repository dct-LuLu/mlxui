/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:51:51 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/27 04:21:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

typedef struct s_button
{
	union
	{
		ANON_GEOM_PACKED;
		t_box	box;
	};
	bool	hover;
	void	*arg;
	void	(*action)(t_hbranch *hbranch, void *arg);
}	t_button;

t_hbranch	*add_button(t_hbranch *parent_branch, t_radius radius, t_border border);
void		hook_click_button(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data);
void		hook_hover_button(t_hbranch *hbranch, t_mlx *mlx_data);

#endif//BUTTON_H
