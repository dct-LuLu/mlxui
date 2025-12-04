# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    button_group.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 00:30:40 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/04 19:09:07 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
BUTTON_GROUP_DIR	= $(COMPONENTS_DIR)/button_group

# Source files
BUTTON_GROUP_SRCS	= add_button_group.c \
					  render_button_group.c \
					  precompute_button_group.c
BUTTON_GROUP_SRCS	:= $(addprefix $(BUTTON_GROUP_DIR)/, $(BUTTON_GROUP_SRCS))

SRCS				+= $(BUTTON_GROUP_SRCS)

# VPATH
vpath %.c $(BUTTON_GROUP_DIR)
