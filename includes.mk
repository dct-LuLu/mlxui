# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    includes.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 07:14:02 by jaubry--          #+#    #+#              #
#    Updated: 2026/01/05 07:42:47 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCDIR			= include

INCDIRS_MLXUI	= components
INCDIRS_MLXUI	:= $(INCDIR) $(addprefix $(INCDIR)/, $(INCDIRS_MLXUI))
