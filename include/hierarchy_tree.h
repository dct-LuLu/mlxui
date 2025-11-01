/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hierarchy_tree.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:09:49 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/01 16:51:44 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIERARCHY_TREE_H
# define HIERARCHY_TREE_H

# include "mlx_wrapper.h"
// store here font, colors, styles etc
typedef struct s_style
{
	t_rgba_int	color;
	t_rgba_int	outline;
	t_rgba_int	accent;
}	t_style;

typedef struct s_hbranch t_hbranch;
typedef struct s_htree t_htree;

typedef struct s_hbranch
{
	bool	hidden;
	t_component_type	type;
	union
	{
		t_geometry;
		t_checkbox	checkbox;
		t_form		form;
		t_text		text;
		t_button	button;
	};
	t_vector	*childs;
	t_hbranch	*parent;
	t_htree		*head;
}	t_hbranch;

typedef struct s_htree
{
	t_mlx		*mlx_data;
	t_style		style;
	t_hbranch	*body;
}	t_htree;

t_htree		init_htree(t_mlx *mlx_data);
t_hbranch	init_hbranch(t_htree *head, t_hbranch *parent, bool hidden);
t_hbranch	*add_branch(t_hbranch *parent_branch, bool hidden);
//int			add_branch(t_hbranch *branch, bool hidden);

void	render_hierarchy(t_htree *htree);
void	precompute_hierarchy(t_htree *htree);

#endif//HIERARCHY_TREE_H
