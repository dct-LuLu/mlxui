/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_form_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 04:13:43 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/25 23:38:33 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

bool	form_is_valid_input(char c)
{
	return ((c >= '0') && (c <= '9'));
}


void	form_btov(void *value, const char buffer[FORM_BUF_SIZE], t_form_type type)
{
	int	*int_value;

	if (type == FORM_INT)
	{
		int_value = (int *)value;
		*int_value = ft_atoi(buffer);
	}
}

void	form_vtob(char buffer[FORM_BUF_SIZE], const void *value, t_form_type type)
{
	if (type == FORM_INT)
		strf(buffer, FORM_BUF_SIZE, "%d", *(int *)value);
}

void	form_format_buf(char buffer[FORM_BUF_SIZE])
{
	size_t	len;

	strf(buffer, FORM_BUF_SIZE, "%d", ft_atoi(buffer));
	len = ft_strlen(buffer);
	if (len < FORM_BUF_SIZE - 3 && false)
	{
		buffer[len] = '.';
		buffer[len + 1] = '0';
		buffer[len + 2] = '\0';
	}
}
