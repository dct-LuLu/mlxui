/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:16:57 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/06 12:50:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

t_texture	*ppm_parser(const int fd, t_texture *tex);

static inline void	create_image(t_hbranch *new, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (pnm_parser(fd, &new->image.img_data) == NULL)
		return (1);
	if (close(fd) != 0)
		return (1);
	new->size.x = new->image.img_data.width;
	new->size.y = new->image.img_data.height;
}

t_hbranch	*add_image(t_hbranch *parent_branch, const char *path)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (NULL);
	new->type = IMAGE;
	new->render = (void (*)(t_hbranch *, void *))render_image;
	create_image(new, path);
	return (new);
}
