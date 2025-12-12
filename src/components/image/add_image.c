/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:16:57 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/12 17:56:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

t_texture	*ppm_parser(const int fd, t_texture *tex);

static inline void	create_image(t_hbranch *new, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("error reading file\n");
	if (ppm_parser(fd, &new->image.img_data) == NULL)
		printf("error parsing ppm\n");
}

t_hbranch	*add_image(t_hbranch *parent_branch, const char *path)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	new->type = IMAGE;
	new->render = (void (*)(t_hbranch *, void *))render_image;
	create_image(new, path);
	return (new);
}
