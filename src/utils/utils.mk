# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 02:50:03 by jaubry--          #+#    #+#              #
#    Updated: 2025/11/27 02:52:05 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
UTILS_DIR	= $(SRCDIR)/utils

# Source files
UTILS_SRCS	= draw_checkmark.c
UTILS_SRCS	:= $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

SRCS		+= $(UTILS_SRCS)

# VPATH
vpath %.c $(UTILS_DIR)
