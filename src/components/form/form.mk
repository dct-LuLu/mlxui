# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    form.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 21:12:25 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/19 16:38:49 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
FORM_DIR	= $(COMPONENTS_DIR)/form

# Source files
FORM_SRCS	= add_form.c \
			  create_form_hooks.c \
			  precompute_form.c \
			  operation_form.c \
			  key_hooks_form.c mouse_hooks_form.c \
			  form_int.c form_float.c \
			  destroy_form.c
FORM_SRCS	:= $(addprefix $(FORM_DIR)/, $(FORM_SRCS))

SRCS			+= $(FORM_SRCS)

# VPATH
vpath %.c $(FORM_DIR)
