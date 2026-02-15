/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:33:28 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/15 06:02:31 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H

# include "geometry_fields.h"
# include "box.h"
# include "checkbox.h"
# include "textbox.h"
# include "form.h"
# include "button.h"
# include "button_group.h"
# include "select.h"
# include "image.h"
# include "scrollbox.h"
# include "slider.h"

typedef struct s_hbranch	t_hbranch;
typedef struct s_htree		t_htree;

void	draw_checkmark(t_vec2i pos, t_rgba_int color, t_img_data *img);
void	draw_down_arrow(t_vec2i pos, t_rgba_int color, t_img_data *img);
bool	is_inside_comp(t_hbranch *hbranch, t_vec2i pos);
void	precompute_geometry(t_hbranch *this,
			size_t render_i, size_t render_num);

#endif//COMPONENTS_H
