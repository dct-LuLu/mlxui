/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hierarchy_tree.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:09:49 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/06 14:58:03 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIERARCHY_TREE_H
# define HIERARCHY_TREE_H

typedef struct s_hbranch t_hbranch;
typedef struct s_htree t_htree;

# include "mlx_wrapper.h"
# include "font_renderer.h"
# include "geometry_fields.h"
# include "components.h"

// store here font, colors, styles etc
typedef struct s_style
{
	t_rgba_int	color;
	t_rgba_int	outline;
	t_rgba_int	accent;
	t_ttf_font	*font;
	t_rgba_int	text_fg;
}	t_style;


typedef struct s_hbranch
{
	bool				visible;
	bool				rendered;
	t_component_type	type;
	union
	{
		ANON_GEOM_PACKED;
		t_box		box;
		t_checkbox	checkbox;
		t_textbox	textbox;
		/*
		t_form		form;
		t_text		text;
		t_button	button;
		*/
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

t_htree		init_htree(t_mlx *mlx_data, t_style style);
t_hbranch	init_hbranch(t_htree *head, t_hbranch *parent);
t_hbranch	*add_branch(t_hbranch *parent_branch);
//int			add_branch(t_hbranch *branch, bool hidden);

void	render_hierarchy(t_htree *htree);
void	precompute_hierarchy(t_htree *htree);

#endif//HIERARCHY_TREE_H
