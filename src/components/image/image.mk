# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    image.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 17:44:15 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/10 10:19:31 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
IMAGE_DIR		= $(COMPONENTS_DIR)/image

# Source files
IMAGE_SRCS	= add_image.c \
			  render_image.c \
			  destroy_image.c
IMAGE_SRCS	:= $(addprefix $(IMAGE_DIR)/, $(IMAGE_SRCS))

SRCS		+= $(IMAGE_SRCS)

# VPATH
vpath %.c $(IMAGE_DIR)
