# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hierarchy.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 18:59:02 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/10 06:17:30 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
HIERARCHY_DIR	= $(SRCDIR)/hierarchy

# Sources
HIERARCHY_SRCS	= init_hierarchy.c \
				  precompute_hierarchy.c \
				  render_hierarchy.c \
				  destroy_hierarchy.c \
				  hbranch_getters.c \
				  hbranch_iterators.c \
				  hbranch_utils.c
HIERARCHY_SRCS	:= $(addprefix $(HIERARCHY_DIR)/, $(HIERARCHY_SRCS))

SRCS			+= $(HIERARCHY_SRCS)

# VPATH
vpath %.c $(HIERARCHY_DIR)
