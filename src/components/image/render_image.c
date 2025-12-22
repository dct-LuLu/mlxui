/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:28:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/22 00:12:30 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

void	render_image(t_hbranch *hbranch, t_image *image)
{
	if (image->img_data.channels == 3)
		ft_mlx_img_put(hbranch->img, hbranch->_lt, &image->img_data);
	else if (image->img_data.channels == 4)
		ft_mlx_img_aput(hbranch->img, hbranch->_lt, &image->img_data);
}
