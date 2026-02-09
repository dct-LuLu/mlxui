# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hierarchy.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 18:59:02 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/09 14:30:15 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
HIERARCHY_DIR	= $(SRCDIR)/hierarchy

# Sources
HIERARCHY_SRCS	= init_hierarchy.c \
				  precompute_hierarchy.c \
				  render_hierarchy.c \
				  hbranch_iterators.c \
				  get_hbranch_from_idx.c \
				  destroy_hierarchy.c
HIERARCHY_SRCS	:= $(addprefix $(HIERARCHY_DIR)/, $(HIERARCHY_SRCS))

SRCS			+= $(HIERARCHY_SRCS)

# VPATH
vpath %.c $(HIERARCHY_DIR)
