/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:33:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/27 03:13:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H

typedef struct s_hbranch t_hbranch;
typedef struct s_htree t_htree;

# include "geometry_fields.h"
# include "box.h"
# include "checkbox.h"
# include "textbox.h"
# include "form.h"
# include "button.h"

void	draw_checkmark(t_vec2i pos, t_rgba_int color, t_mlx *mlx_data);
void	precompute_geometry(t_hbranch *this, size_t render_i, size_t render_num);

#endif//COMPONENTS_H
