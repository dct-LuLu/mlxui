/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/04 12:12:20 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKBOX_H
# define CHECKBOX_H

# include "box.h"

typedef struct s_checkbox
{
	union
	{
		ANON_GEOM_PACKED;
		t_box	box;
	};
	bool	*checked;
}	t_checkbox;

t_hbranch	*add_checkbox(t_hbranch *parent_branch, bool *checked);
void	precompute_checkbox(t_hbranch *hbranch);
void	render_checkbox(t_hbranch *hbranch, t_checkbox *checkbox);
void	switch_checkbox(t_hbranch *checkbox);
void	hook_checkbox(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data);

#endif//CHECKBOX_H
