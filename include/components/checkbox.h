/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 22:24:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKBOX_H
# define CHECKBOX_H

# include "box.h"

struct s_hbranch;

typedef struct s_checkbox
{
	union
	{
		ANON_GEOM_PACKED;
		t_box	box;
	};
	bool	*checked;
}	t_checkbox;

struct s_hbranch	*add_checkbox(struct s_hbranch *parent_branch, bool *checked);
void	precompute_checkbox(struct s_hbranch *hbranch);
void	render_checkbox(struct s_hbranch *hbranch, t_checkbox *checkbox);
void	switch_checkbox(struct s_hbranch *checkbox);
void	hook_checkbox(t_vec2i pos, t_maction action, t_hbranch *hbranch, t_mlx *mlx_data);

#endif//CHECKBOX_H
