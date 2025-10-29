# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hierarchy.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 18:59:02 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/29 19:58:10 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
HIERARCHY_DIR	= $(SRCDIR)/hierarchy

# Sources
HIERARCHY_SRCS	= init_hierarchy.c \
				  render_hierarchy.c
HIERARCHY_SRCS	:= $(addprefix $(HIERARCHY_DIR)/, $(HIERARCHY_SRCS))

SRCS			+= $(HIERARCHY_SRCS)
# Vpath
vpath %.c $(HIERARCHY_DIR)
