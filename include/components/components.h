/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:33:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/04 12:12:38 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H

typedef struct s_hbranch t_hbranch;
typedef struct s_htree t_htree;

# include "geometry_fields.h"
# include "box.h"
# include "checkbox.h"

void	precompute_geometry(t_hbranch *this, size_t render_i, size_t render_num);
/*
#pragma pack(push, 1)

typedef struct;
{
	t_anchor	anchor;	
	struct
	{
		t_vec2i	pos; // possible ?
		void	(*x_pos_operation)(size_t, t_hbranch *, size_t, size_t);
		void	(*y_pos_operation)(size_t, t_hbranch *, size_t, size_t);
	};
	struct
	{
		t_vec2i	size;
		void	(*x_size_operation)(size_t, t_hbranch *, size_t, size_t);
		void	(*y_size_operation)(size_t, t_hbranch *, size_t, size_t);
	};
	void	(*precompute)(t_hbranch *);
	void	(*render)(t_hbranch *, void *);
	t_vec2	_half_size;
	t_vec2i	_mid;
	t_vec2i	_lt;
	t_vec2i	_rt;
	t_vec2i	_lb;
	t_vec2i	_rb;
}	t_geometry;

#pragma pack(pop)
*/

#endif//COMPONENTS_H
