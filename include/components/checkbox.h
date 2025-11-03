/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/03 12:24:51 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKBOX_H
# define CHECKBOX_H

typedef struct s_checkbox
{
	union
	{
		t_geometry;
		t_box	box;
	};
	bool	*checked;
}	t_checkbox;

#endif//CHECKBOX_H
