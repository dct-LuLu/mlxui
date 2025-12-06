# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    components.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 19:11:39 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/06 09:35:16 by jaubry--         ###   ########.fr        #
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
		  textbox \
		  form \
		  button \
		  button_group \
		  select

include $(foreach n,$(MKS),$(COMPONENTS_DIR)/$(n)/$(n).mk)

# VPATH
vpath %.c $(COMPONENTS_DIR)
