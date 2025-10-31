/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:33:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/30 18:38:58 by jaubry--         ###   ########.fr       */
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

typedef enum e_relation_type
{
	INHERIT,
	ADAPT,
	ABSOLUTE
}	t_relation_type;

typedef struct s_relation
{
	t_relation_type	type;
	int (*)()		operation;
	int				min;
	int				max;
	int				*val;
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

typedef struct
{
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

	t_anchor	anchor;	

	t_vec2		_half_size;
	t_vec2i		_mid;
	t_vec2i		_lt;
	t_vec2i		_rt;
	t_vec2i		_lb;
	t_vec2i		_rb;
}	t_geometry;



#endif//COMPONENTS_H
