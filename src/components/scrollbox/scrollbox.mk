# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scrollbox.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 22:16:30 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/22 01:44:02 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SCROLLBOX_DIR	= $(COMPONENTS_DIR)/scrollbox

# Source files
SCROLLBOX_SRCS	= add_scrollbox.c \
				  precompute_scrollbox.c \
				  render_scrollbox.c \
				  mouse_hooks_scrollbox.c
SCROLLBOX_SRCS	:= $(addprefix $(SCROLLBOX_DIR)/, $(SCROLLBOX_SRCS))

SRCS			+= $(SCROLLBOX_SRCS)

# VPATH
vpath %.c $(SCROLLBOX_DIR)
