# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    textbox.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:09:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/11/06 14:07:13 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
TEXTBOX_DIR	= $(COMPONENTS_DIR)/textbox

# Source files
TEXTBOX_SRCS	= add_textbox.c \
				  precompute_textbox.c \
				  render_textbox.c
TEXTBOX_SRCS	:= $(addprefix $(TEXTBOX_DIR)/, $(TEXTBOX_SRCS))

SRCS			+= $(TEXTBOX_SRCS)

# VPATH
vpath %.c $(TEXTBOX_DIR)
