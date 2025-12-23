# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    box.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:09:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/23 21:51:44 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
BOX_DIR		= $(COMPONENTS_DIR)/box

# Source files
BOX_SRCS	= add_box.c \
			  precompute_box.c \
			  render_box.c \
			  precompute_radius.c \
			  precompute_corner_radius.c \
			  render_border.c
BOX_SRCS	:= $(addprefix $(BOX_DIR)/, $(BOX_SRCS))

SRCS		+= $(BOX_SRCS)

# VPATH
vpath %.c $(BOX_DIR)
