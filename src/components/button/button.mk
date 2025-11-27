# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    button.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 04:22:52 by jaubry--          #+#    #+#              #
#    Updated: 2025/11/27 04:24:37 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
BUTTON_DIR	= $(COMPONENTS_DIR)/button

# Source files
BUTTON_SRCS	= add_button.c \
			  mouse_hooks_button.c
BUTTON_SRCS	:= $(addprefix $(BUTTON_DIR)/, $(BUTTON_SRCS))

SRCS		+= $(BUTTON_SRCS)

# VPATH
vpath %.c $(BUTTON_DIR)
