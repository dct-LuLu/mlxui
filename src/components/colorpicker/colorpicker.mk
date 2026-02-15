# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    colorpicker.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 17:44:15 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/15 08:37:10 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
COLORPICKER_DIR		= $(COMPONENTS_DIR)/colorpicker

# Source files
COLORPICKER_SRCS	= add_colorpicker.c \
					  render_colorpicker.c \
					  precompute_colorpicker.c \
					  mouse_hooks_colorpicker.c \
					  colorpicker_utils.c \
					  destroy_colorpicker.c
COLORPICKER_SRCS	:= $(addprefix $(COLORPICKER_DIR)/, $(COLORPICKER_SRCS))

SRCS		+= $(COLORPICKER_SRCS)

# VPATH
vpath %.c $(COLORPICKER_DIR)
