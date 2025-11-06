# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    components.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 19:11:39 by jaubry--          #+#    #+#              #
#    Updated: 2025/11/06 14:07:32 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
COMPONENTS_DIR	= $(SRCDIR)/components

# Source files
COMPONENTS_SRCS	= precompute_geometry.c
COMPONENTS_SRCS	:= $(addprefix $(COMPONENTS_DIR)/, $(COMPONENTS_SRCS))

SRCS			+= $(COMPONENTS_SRCS)

# MKs

MKS		= box \
		  checkbox \
		  textbox

include $(foreach n,$(MKS),$(COMPONENTS_DIR)/$(n)/$(n).mk)

# VPATH
vpath %.c $(COMPONENTS_DIR)
