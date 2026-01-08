/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlxui_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:24:55 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/08 16:21:48 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "mlxui_xcerrcal.h"

void	register_mlxui_errors(void)
{
	const char	*err_msgs[] = {
		MLXUI_E_MSG_IBR,
		MLXUI_E_MSG_ABR,
		MLXUI_E_MSG_FSCOMP,
		MLXUI_E_MSG_FIMG,
		MLXUI_E_MSG_COMP,
	};

	bulk_register_error(MLXUI_ERRS_NUM - 1, MLXUI_ID, (const char **)err_msgs);
}
