/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:10:48 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 21:08:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

void	operation_half(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	center_screen(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);
void	copy(size_t field_offset, t_hbranch *this,
			size_t render_i, size_t render_num);

#endif//OPERATIONS_H
