# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 08:18:04 by jaubry--          #+#    #+#              #
#    Updated: 2026/01/08 16:21:29 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKS		= components \
		  hierarchy \
		  operations \
		  utils \
		  test

include $(foreach n,$(MKS),$(SRCDIR)/$(n)/$(n).mk)

SRCS += $(SRCDIR)/register_mlxui_errors.c

vpath %.c $(SRCDIR)
