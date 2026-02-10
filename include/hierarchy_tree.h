/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hierarchy_tree.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:09:49 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 06:15:02 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIERARCHY_TREE_H
# define HIERARCHY_TREE_H

# include "mlxui_xcerrcal.h"
# include "mlx_wrapper.h"
# include "font_renderer.h"
# include "geometry_fields.h"
# include "components.h"

typedef struct s_hbranch	t_hbranch;
typedef struct s_htree		t_htree;

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
}				t_style;

typedef struct s_hbranch
{
	bool				visible;
	bool				rendered;
	t_component_type	type;
	union
	{
		struct __attribute__((packed))
		{
			t_anchor	anchor;
			struct
			{
				t_vec2i	pos;
				void	(*x_pos_operation)(size_t, t_hbranch *,
						size_t, size_t);
				void	(*y_pos_operation)(size_t, t_hbranch *,
						size_t, size_t);
			};
			struct
			{
				t_vec2i	size;
				void	(*x_size_operation)(size_t, t_hbranch *,
						size_t, size_t);
				void	(*y_size_operation)(size_t, t_hbranch *,
						size_t, size_t);
			};
			int			(*precompute)(t_hbranch *);
			void		(*render)(t_hbranch *, void *);
			t_vec2		_half_size;
			t_vec2i		_mid;
			t_vec2i		_lt;
			t_vec2i		_rt;
			t_vec2i		_lb;
			t_vec2i		_rb;
			t_img_data	*img;
			t_hbranch	*_in_scrollbox;
		};
		t_box			box;
		t_checkbox		checkbox;
		t_textbox		textbox;
		t_form			form;
		t_button		button;
		t_button_group	button_group;
		t_select		select;
		t_image			image;
		t_scrollbox		scrollbox;
	};
	t_vector			*childs;
	t_hbranch			*parent;
	t_htree				*head;
}						t_hbranch;

typedef struct s_htree
{
	t_mlx		*mlx_data;
	t_style		style;
	t_hbranch	*body;
	t_vector	refs;// t_hbranch* (stable, never shrinks)
	t_vector	free_slots;	 // size_t (NEW: reasable indices)
}				t_htree;

t_htree		init_htree(t_mlx *mlx_data, t_style style);
void		free_htree(t_htree *htree);

t_hbranch	*add_branch(t_hbranch *parent_branch);
void		delete_node(t_hbranch *node);
void		delete_node_childs(t_hbranch *hbranch);

t_hbranch	*get_child(t_hbranch *parent, size_t idx);

void		render_hierarchy(t_htree *htree);
int			precompute_hierarchy(t_htree *htree);

void		release_slot(t_htree *htree, size_t idx);
size_t		alloc_slot(t_htree *htree);

t_hbranch   *ref_at(t_htree *htree, size_t idx);
t_hbranch   *get_hbranch_child_idx(t_hbranch *parent, size_t idx);
ssize_t	get_hbranch_index(t_vector *v, t_hbranch *hbranch);
/*
t_hbranch   *get_hbranch_ref_idx(t_htree *htree, size_t idx);
t_hbranch   *get_hbranch_child_idx(t_hbranch *parent, size_t idx);
ssize_t		get_hbranch_index(t_vector *v, t_hbranch *hbranch);

size_t      get_next_slot(t_htree *htree);
void        mark_slot_free(t_htree *htree, size_t idx);
*/

int			get_hbranch_max(size_t field_offset, t_hbranch *hbranch);
int			get_hbranch_total(size_t field_offset, t_hbranch *hbranch);

#endif//HIERARCHY_TREE_H
