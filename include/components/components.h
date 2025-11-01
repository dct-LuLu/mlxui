/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:33:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/01 17:28:32 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H

typedef enum e_component_type
{
	EMPTY,
	BOX,
	TEXT,
	CHECKBOX,
	BUTTON,
	FORM
}	t_component_type;

/*
typedef enum e_relation_type
{
	INHERIT,
	ADAPT,
	ABSOLUTE
}	t_relation_type;

typedef enum e_flex_type//affects child
{
	NO_FLEX,
	SPAN_X,
	SPAN_Y,
	SURROUND_X,
	SURROUND_Y,
	SPACE_X,
	SPACE_Y,
	CONTIGU_X_LEFT,
	CONTIGU_X_RIGHT,
	CONTIGU_Y_TOP,
	CONTIGU_Y_BOTTOM
}	t_flex_type;

typedef enum e_pos_type
{
	PX,
	PERCENTAGE,
	OPERATION
}	t_pos_type;
*/

typedef struct s_relation
{
	void (*)(size_t, t_hbranch *, void *)	operation;
	union
	{
		void	*arg;
		uint8_t	percentage;
	};
	//t_relation_type	rtype;
	//t_pos_type		ptype;
	//int				min;
	//int				max;
}	t_relation;

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

#pragma pack(push, 1)

typedef struct
{
	t_anchor	anchor;	
	t_vec2i		pos;
	struct s_rpos
	{
		t_relation	x;
		t_relation	y;
	}	rpos;

	t_vec2i		size;
	struct rsize
	{
		t_relation	x;
		t_relation	y;
	}	rsize;

	//t_flex_type	flex;
	//t_vec2i	margin;
	//t_vec2i	padding;
	t_vec2		_half_size;
	t_vec2i		_mid;
	t_vec2i		_lt;
	t_vec2i		_rt;
	t_vec2i		_lb;
	t_vec2i		_rb;
}	t_geometry;

#pragma pack(pop)


#endif//COMPONENTS_H
