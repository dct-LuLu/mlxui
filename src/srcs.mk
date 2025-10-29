# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 08:18:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/29 19:05:02 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS	= test.c
#SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))

include $(SRCDIR)/hierarchy/hierarchy.mk
include $(SRCDIR)/test/test.mk

vpath %.c $(SRCDIR)
