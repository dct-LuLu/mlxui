/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hierarchy_tree.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:09:49 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/29 00:34:04 by jaubry--         ###   ########.fr       */
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
	t_ttf_font	*font;
	int			radius;
	t_rgba_int	background;
	t_rgba_int	foreground;
	t_rgba_int	card;
	t_rgba_int	primary;
	t_rgba_int	primary_fg;
	t_rgba_int	secondary;
	t_rgba_int	secondary_fg;
	t_rgba_int	muted;
	t_rgba_int	muted_fg;
	t_rgba_int	accent;
	t_rgba_int	accent_fg;
	t_rgba_int	destructive;
	t_rgba_int	border;
	t_rgba_int	input;
}	t_style;


typedef struct s_hbranch
{
	bool				visible;
	bool				rendered;
	t_component_type	type;
	union
	{
		ANON_GEOM_PACKED;
		t_box			box;
		t_checkbox		checkbox;
		t_textbox		textbox;
		t_form			form;
		t_button		button;
		t_button_group	button_group;
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
