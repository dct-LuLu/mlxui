/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_fields.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:57:51 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/12 15:41:31 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_FIELDS_H
# define GEOMETRY_FIELDS_H

typedef enum e_component_type
{
	EMPTY,
	BOX,
	CHECKBOX,
	TEXTBOX,
	BUTTON,
	BUTTON_GROUP,
	FORM,
	SELECT,
	IMAGE
}	t_component_type;

typedef enum e_anchor
{
	CENTER,
	LT,
	TOP,
	RT,
	RIGHT,
	RB,
	BOTTOM,
	LB,
	LEFT
}	t_anchor;

# define GEOMETRY_FIELDS													\
	t_anchor	anchor;														\
	struct																	\
	{																		\
		t_vec2i	pos;														\
		void	(*x_pos_operation)(size_t, t_hbranch *, size_t, size_t);	\
		void	(*y_pos_operation)(size_t, t_hbranch *, size_t, size_t);	\
	};																		\
	struct																	\
	{																		\
		t_vec2i	size;														\
		void	(*x_size_operation)(size_t, t_hbranch *, size_t, size_t);	\
		void	(*y_size_operation)(size_t, t_hbranch *, size_t, size_t);	\
	};																		\
	void	(*precompute)(t_hbranch *);										\
	void	(*render)(t_hbranch *, void *);									\
	t_vec2	_half_size;														\
	t_vec2i	_mid;															\
	t_vec2i	_lt;															\
	t_vec2i	_rt;															\
	t_vec2i	_lb;															\
	t_vec2i	_rb;

// canonical packed type
typedef struct __attribute__((__packed__)) s_geometry
{
	GEOMETRY_FIELDS
}	t_geometry;

// anonymous packed subobject for embedding
# define ANON_GEOM_PACKED  struct { GEOMETRY_FIELDS } __attribute__((__packed__))

#endif//GEOMETRY_FIELDS_H
