# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    slider.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 05:55:35 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/15 08:03:29 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SLIDER_DIR	= $(COMPONENTS_DIR)/slider

# Source files
SLIDER_SRCS	= add_slider.c \
			  render_slider.c \
			  mouse_hooks_slider.c \
			  destroy_slider.c \
			  precompute_slider.c \
			  slider_scale.c

SLIDER_SRCS	:= $(addprefix $(SLIDER_DIR)/, $(SLIDER_SRCS))

SRCS		+= $(SLIDER_SRCS)

# VPATH
vpath %.c $(SLIDER_DIR)
