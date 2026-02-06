# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 06:15:56 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/06 06:22:05 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
TEST_DIR	= $(SRCDIR)/test

# Source files
TEST_SRCS	= main.c

TEST_SRCS	:= $(addprefix $(TEST_DIR)/, $(TEST_SRCS))

# VPATH
vpath %.c $(TEST_DIR)
