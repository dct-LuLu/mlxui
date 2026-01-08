/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:16:57 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/08 16:16:39 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

t_texture	*ppm_parser(const int fd, t_texture *tex);

static inline int	create_image(t_hbranch *new, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (pnm_parser(fd, &new->image.img_data) == NULL)
		return (error(pack_err(MLXW_ID, MLXW_E_PNM), FL, LN, FC));
	if (close(fd) != 0)
		return (1);
	new->size.x = new->image.img_data.width;
	new->size.y = new->image.img_data.height;
	return (0);
}

t_hbranch	*add_image(t_hbranch *parent_branch, const char *path)
{
	t_hbranch	*new;

	new = add_branch(parent_branch);
	if (!new)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_ABR), FL, LN, FC));
	new->type = IMAGE;
	new->render = (void (*)(t_hbranch *, void *))render_image;
	if (create_image(new, path) != 0)
		return (nul_error(pack_err(MLXUI_ID, MLXUI_E_FIMG), FL, LN, FC));
	return (new);
}
