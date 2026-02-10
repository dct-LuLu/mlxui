# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checkbox.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:09:04 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/10 10:19:12 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
CHECKBOX_DIR	= $(COMPONENTS_DIR)/checkbox

# Source files
CHECKBOX_SRCS	= add_checkbox.c \
				  render_checkbox.c \
				  hooks_checkbox.c \
				  destroy_checkbox.c
CHECKBOX_SRCS	:= $(addprefix $(CHECKBOX_DIR)/, $(CHECKBOX_SRCS))

SRCS			+= $(CHECKBOX_SRCS)

# VPATH
vpath %.c $(CHECKBOX_DIR)
