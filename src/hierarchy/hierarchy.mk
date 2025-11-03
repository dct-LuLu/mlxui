# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hierarchy.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 18:59:02 by jaubry--          #+#    #+#              #
#    Updated: 2025/11/03 19:06:31 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
HIERARCHY_DIR	= $(SRCDIR)/hierarchy

# Sources
HIERARCHY_SRCS	= init_hierarchy.c \
				  precompute_hierarchy.c \
				  render_hierarchy.c
HIERARCHY_SRCS	:= $(addprefix $(HIERARCHY_DIR)/, $(HIERARCHY_SRCS))

SRCS			+= $(HIERARCHY_SRCS)

# VPATH
vpath %.c $(HIERARCHY_DIR)
