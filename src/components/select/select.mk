# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    select.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 09:24:54 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/10 11:37:40 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SELECT_DIR	= $(COMPONENTS_DIR)/select

# Source files
SELECT_SRCS	= add_select.c \
			  add_select_option.c \
			  render_select.c \
			  mouse_hooks_select.c \
			  operation_select.c

SELECT_SRCS	:= $(addprefix $(SELECT_DIR)/, $(SELECT_SRCS))

SRCS		+= $(SELECT_SRCS)

# VPATH
vpath %.c $(SELECT_DIR)
