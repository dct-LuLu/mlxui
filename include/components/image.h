/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:33:04 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/12 17:57:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	ANON_GEOM_PACKED;
	t_img_data	img_data;
}	t_image;

t_hbranch	*add_image(t_hbranch *parent_hbranch, const char *path);
void	render_image(t_hbranch *hbranch, t_image *image);

#endif//IMAGE_H
