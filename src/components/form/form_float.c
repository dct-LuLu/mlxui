/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:15:34 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 13:08:44 by jaubry--         ###   ########.fr       */
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
	printf("form_btov_float:{value:'%f', float_value:'%f', buffer:'%s'}\n",
		*(float *)value, *float_value, buffer);
}

void	form_vtob_float(char buffer[FORM_BUF_SIZE], const void *value)
{
	int		int_part;
	int		frac_part;
	float	temp;
	float	frac_temp;
	char	frac_str[6];
	int		i;

	temp = *(float *)value;
	int_part = (int)temp;
	frac_temp = fabsf((temp - (float)int_part) * 10000.0f);
	frac_part = (int)(frac_temp + 0.5f);
	if (frac_part >= 10000)
	{
		frac_part = 0;
		if (temp >= 0)
			int_part++;
		else
			int_part--;
	}
	i = 3;
	while (i >= 0)
	{
		frac_str[i] = (frac_part % 10) + '0';
		if (i && (frac_str[i] == '0'))
			frac_str[i] = '\0';
		frac_part /= 10;
		i--;
	}
	frac_str[4] = '\0';
	strf(buffer, FORM_BUF_SIZE, "%d.%s", int_part, frac_str);
}

void	form_format_buf_float(char buffer[FORM_BUF_SIZE])
{
	float	val;

	form_btov_float(&val, buffer);
	form_vtob_float(buffer, &val);
}

/*
void	form_format_buf_float(char buffer[FORM_BUF_SIZE])
{
	size_t	len;
	size_t	dot_pos;
	
	// Handle empty or invalid input
	if (!buffer[0] || (buffer[0] == '-' && !buffer[1]))
	{
		strf(buffer, FORM_BUF_SIZE, "0.0");
		return ;
	}
	
	// If already formatted (has exactly 2 decimals after dot), don't reformat
	len = ft_strlen(buffer);
	dot_pos = 0;
	while (dot_pos < len && buffer[dot_pos] != '.')
		dot_pos++;
	if (dot_pos < len && (len - dot_pos - 1) <= 2)
		return ;  // Already in display format, don't touch it
	
	// Truncate to 2 decimals by just cutting the string
	if (dot_pos < len && (len - dot_pos - 1) > 2)
	{
		buffer[dot_pos + 3] = '\0';  // Keep X.XX format
		len = dot_pos + 3;
	}
	
	// Remove trailing zeros (but keep at least one decimal)
	while ((len > 0) && (buffer[len - 1] == '0'))
	{
		buffer[--len] = '\0';
		if (len > 0 && buffer[len - 1] == '.')
		{
			buffer[len++] = '0';
			break;
		}
	}
}
*/
