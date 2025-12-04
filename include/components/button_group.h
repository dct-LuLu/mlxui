/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_group.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:32:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/04 19:09:16 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_GROUP_H
# define BUTTON_GROUP_H

typedef enum e_group_dir
{
	GROUP_HORZ,
	GROUP_VERT
}	t_group_dir;

typedef enum e_group_type
{
	GROUP_DEFAULT,
	GROUP_SWITCH
}	t_group_type;

typedef struct s_button_group
{
	ANON_GEOM_PACKED;
	t_group_dir		group_dir;
	t_group_type	group_type;
	size_t			switched_index;
}	t_button_group;

t_hbranch	*add_button_group(t_hbranch *parent_branch, t_group_dir group_dir, t_group_type group_type);
void	render_button_group_switch(t_hbranch *hbranch);
void	precompute_button_group(t_hbranch *hbranch);

#endif//BUTTON_GROUP_H
