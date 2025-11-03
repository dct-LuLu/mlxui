# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 19:05:16 by jaubry--          #+#    #+#              #
#    Updated: 2025/11/03 19:06:22 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
OPERATIONS_DIR	= $(SRCDIR)/operations

# Sources
OPERATIONS_SRCS	= operation_half.c
OPERATIONS_SRCS	:= $(addprefix $(OPERATIONS_DIR)/, $(OPERATIONS_SRCS))

SRCS			+= $(OPERATIONS_SRCS)

# VPATH
vpath %.c $(OPERATIONS_DIR)
