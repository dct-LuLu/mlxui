/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:15:34 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 16:34:12 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hierarchy_tree.h"

bool	form_is_valid_input_float(char c)
{
	return (ft_isdigit(c) || (c == '.') || (c == '-') || (c == '+'));
}

void	form_btov_float(void *value, const char buffer[FORM_BUF_SIZE])
{
	float	*float_value;

	float_value = (float *)value;
	*float_value = ft_atod(buffer);
}

void	form_vtob_float(char buffer[FORM_BUF_SIZE], const void *value)
{
	strf(buffer, FORM_BUF_SIZE, "%.4g", *(float *)value);
}

void	form_format_buf_float(char buffer[FORM_BUF_SIZE])
{
	float	val;

	form_btov_float(&val, buffer);
	form_vtob_float(buffer, &val);
}
