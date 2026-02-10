/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 04:13:43 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 12:52:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

bool	form_is_valid_input_int(char c)
{
	return (ft_isdigit(c));
}

void	form_btov_int(void *value, const char buffer[FORM_BUF_SIZE])
{
	int	*int_value;

	int_value = (int *)value;
	*int_value = ft_atoi(buffer);
}

void	form_vtob_int(char buffer[FORM_BUF_SIZE], const void *value)
{
	strf(buffer, FORM_BUF_SIZE, "%d", *(int *)value);
}

void	form_format_buf_int(char buffer[FORM_BUF_SIZE])
{
	int	val;

	form_btov_int(&val, buffer);
	form_vtob_int(buffer, &val);
}
