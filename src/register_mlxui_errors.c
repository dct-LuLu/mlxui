/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlxui_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:24:55 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/06 09:26:01 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "mlxui_xcerrcal.h"

void	register_mlxui_errors(void)
{
	const char	*err_msgs[] = {
		MLXUI_E_MSG_TEST
	};

	bulk_register_errors(MLXUI_ERRS_NUM - 1, MLXUI_ID, (const char **)err_msgs);
}
