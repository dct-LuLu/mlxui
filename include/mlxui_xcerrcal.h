/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxui_xcerrcal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:22:16 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/06 09:45:46 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXUI_XCERRCAL_H
# define MLXUI_XCERRCAL_H

# define MLXUI_ID 5

typedef enum e_mlxui_err
{
	MLXUI_E_IBR = 1,
	MLXUI_E_ABR,
	MLXUI_E_FCOMP,
	MLXUI_ERRS_NUM
}	t_mlxui_err;

#define MLXUI_E_MSG_IBR "Failed to initialize new hierarchy branch"
#define MLXUI_E_MSG_ABR "Failed to insert new branch into the hierarchy tree"
#define MLXUI_E_MSG_FCOMP "Could not create new %s component branch and insert it inside the hierarchy tree"
#define MLXUI_E_MSG_FSCOMP "Could not create new % internal component for %s and insert it inside the hierarchy tree"
#define MLXUI_E_MSG_FHCOMP "Could not create necessary hooks for new %s component"

void	register_mlxui_errors(void);

#endif//MLXUI_XCERRCAL_H
