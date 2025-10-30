# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 10:16:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/30 09:38:51 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR		?= .
include $(ROOTDIR)/mkidir/make_utils.mk

LIBNAME		= mlxui

# Variables
WINDOWLESS	= 0
FULLSCREEN	= 0
RESIZEABLE	= 0
ifeq ($(FULLSCREEN), 1)
WIDTH		= $(MAX_WIDTH)
HEIGHT		= $(MAX_HEIGHT)
else
WIDTH		= 500
HEIGHT		= 500
endif
PERF		= 0

# Directories
CDIR		= $(LIBNAME)
SRCDIR		= src
INCDIR		= include
OBJDIR		= .obj
DEPDIR		= .dep

XCERRCALDIR	= $(LIBDIR)/xcerrcal
LIBFTDIR	= $(LIBDIR)/libft
MLXDIR		= $(LIBDIR)/minilibx-linux
MLXWDIR		= $(LIBDIR)/mlx_wrapper
FONT_RENDIR	= $(LIBDIR)/font_renderer

# Output
NAME		= lib$(LIBNAME).a
XCERRCAL	= $(XCERRCALDIR)/libxcerrcal.a
LIBFT		= $(LIBFTDIR)/libft.a
MLX			= $(MLXDIR)/libmlx.a
MLXW		= $(MLXWDIR)/libmlx-wrapper.a
FONT_RENDER	= $(FONT_RENDIR)/libfont-renderer.a
ARCHIVES	= $(XCERRCAL) $(LIBFT) $(MLX) $(MLXW) $(FONT_RENDER)

# Compiler and flags
CC			= cc

CFLAGS		= -Wall -Wextra -Werror \
			  -std=gnu11

DFLAGS		= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS		= -I$(INCDIR) \
			  -I$(XCERRCALDIR)/include \
			  -I$(LIBFTDIR)/include \
			  -I$(MLXDIR) \
			  -I$(MLXWDIR)/include \
			  -I$(FONT_RENDIR)/include

LFLAGS		= -L$(FONT_RENDIR) \
			  -L$(MLXWDIR) \
			  -L$(LIBFTDIR) \
			  -L$(MLXDIR) \
			  -L$(XCERRCALDIR) \
			  -L$(NAME) \
			  -lfont-renderer -lmlx-wrapper -lmlx -lft -lxcerrcal \
			  -lXext -lX11 -lXrandr -lm

VARS		= DEBUG=$(DEBUG) \
			  WIDTH=$(WIDTH) \
			  HEIGHT=$(HEIGHT) \
			  PERF=$(PERF) \
			  FULLSCREEN=$(FULLSCREEN) \
			  RESIZEABLE=$(RESIZEABLE) \
			  WINDOWLESS=$(WINDOWLESS)
VFLAGS		= $(addprefix -D ,$(VARS))

CFLAGS		+= $(DEBUG_FLAGS) $(FFLAGS) $(VFLAGS)

CF			= $(CC) $(CFLAGS) $(IFLAGS)

AR			= $(if $(findstring -flto,$(FFLAGS)),$(FAST_AR),$(STD_AR))
ARFLAGS		= rcs
RANLIB		= $(if $(findstring -flto,$(FFLAGS)),$(FAST_RANLIB),$(STD_RANLIB))

# Sources
include $(SRCDIR)/srcs.mk

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.c=.d)))
INCLUDES	= mlxui.h
INCLUDES	:= $(addprefix $(INCDIR)/, $(INCLUDES))

# VPATH
vpath %.h $(INCDIR) $(LIBFTDIR)/$(INCDIR) $(XCERRCALDIR)/$(INCDIR) $(MLXWDIR)/$(INCDIR) $(MLXDIR) $(FONT_RENDIR)/$(INCDIR)
vpath %.o $(OBJDIR) $(LIBFTDIR)/$(OBJDIR) $(XCERRCALDIR)/$(OBJDIR) $(MLXWDIR)/$(OBJDIR) $(FONT_RENDIR)/$(OBJDIR)
vpath %.d $(DEPDIR) $(LIBFTDIR)/$(DEPDIR) $(XCERRCALDIR)/$(DEPDIR) $(MLXWDIR)/$(DEPDIR) $(FONT_RENDIR)/$(DEPDIR)

all:	$(NAME)
fast:	$(NAME)
debug:	$(NAME)

$(NAME): $(XCERRCAL) $(FONT_RENDER) $(MLXW) $(MLX) $(LIBFT) $(OBJS) $(INCLUDES)
	$(call ar-msg)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
ifeq ($(FAST),1)
	@$(RANLIB) $@
endif
	$(call ar-finish-msg)

test: $(NAME)
	$(CF) $(TEST_SRCS) $(ARCHIVES) $^ $(LFLAGS) -o $@

$(XCERRCAL):
	@$(MAKE) -s -C $(XCERRCALDIR) $(RULE) $(VARS) ROOTDIR=../..

$(FONT_RENDER): $(MLXW) $(MLX) $(LIBFT)
	@$(MAKE) -s -C $(FONT_RENDIR) $(RULE) $(VARS) ROOTDIR=../..

$(MLXW): $(MLX) $(LIBFT)
	@$(MAKE) -s -C $(MLXWDIR) $(RULE) $(VARS) ROOTDIR=../..

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR) $(RULE) $(VARS) ROOTDIR=../..

$(MLX):
	$(call mlx-build-msg)
	@$(MAKE) -s -C $(MLXDIR) CC="$(MLX_GCC) $(if $(filter 1,$(FAST)),$(OFLAGS))" $(MUTE)
	$(call mlx-finish-msg)

$(OBJDIR)/%.o: %.c $(INCLUDES) | buildmsg $(OBJDIR) $(DEPDIR)
	$(call lib-compile-obj-msg)
	@$(CF) $(DFLAGS) -c $< -o $@

$(OBJDIR) $(DEPDIR):
	$(call create-dir-msg)
	@mkdir -p $@

buildmsg:
ifneq ($(shell [ -f $(NAME) ] && echo exists),exists)
	$(call lib-build-msg)
endif

help:
	@echo "Available targets:"
	@echo -e "\tall, $(NAME)\t\t: Build the library"
	@echo -e "\tdebug\t\t\t\t: Build the library with debug symbols"
	@echo -e "\tre\t\t\t\t: Rebuild $(NAME)"
	@echo
	@echo -e "\tclean\t\t\t\t: Remove object files"
	@echo -e "\tfclean\t\t\t\t: Remove object files, libraries"
	@echo
	@echo -e "\tprint-%\t\t\t\t: Prints makefile variable content when replacing '%'"

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

clean:
	@$(MAKE) -s -C $(FONT_RENDIR) clean ROOTDIR=../..
	$(call rm-obj-msg)
	@rm -rf $(OBJDIR) $(DEPDIR)

fclean:
	@$(MAKE) -s -C $(FONT_RENDIR) fclean ROOTDIR=../..
	$(call rm-obj-msg)
	@rm -rf $(OBJDIR) $(DEPDIR)
	$(call rm-lib-msg)
	@rm -f $(NAME)

re:		fclean all
refast:	fclean fast
redebug:fclean debug

-include $(DEPS)

.PHONY: all test re debug redebug fast refast clean fclean help buildmsg print-%
