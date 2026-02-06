# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 10:16:04 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/06 06:27:04 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR		?= .
include $(ROOTDIR)/mkidir/make_utils.mk

LIBNAME		= libmlxui

# Directories
CDIR		= mlxui
SRCDIR		= src
OBJDIR		= .obj
DEPDIR		= .dep

XCERRCALDIR	= $(LIBDIR)/xcerrcal
LIBFTDIR	= $(LIBDIR)/libft
MLXDIR		= $(LIBDIR)/minilibx-linux
MLXWDIR		= $(LIBDIR)/mlx_wrapper
FONT_RENDIR	= $(LIBDIR)/font_renderer

# Includes
include $(LIBFTDIR)/includes.mk $(XCERRCALDIR)/includes.mk \
	$(MLXWDIR)/includes.mk $(FONT_RENDIR)/includes.mk includes.mk

INCLUDES	= $(INCDIRS_MLXUI) \
			  $(addprefix $(XCERRCALDIR)/, $(INCDIRS_XCERRCAL)) \
			  $(addprefix $(LIBFTDIR)/, $(INCDIRS_LIBFT)) \
			  $(MLXDIR) \
			  $(addprefix $(MLXWDIR)/, $(INCDIRS_MLXW)) \
			  $(addprefix $(FONT_RENDIR)/, $(INCDIRS_FTRDR))

# Output
NAME		= $(LIBNAME).a
XCERRCAL	= $(XCERRCALDIR)/libxcerrcal.a
LIBFT		= $(LIBFTDIR)/libft.a
MLX			= $(MLXDIR)/libmlx.a
MLXW		= $(MLXWDIR)/libmlx-wrapper.a
FONT_RENDER	= $(FONT_RENDIR)/libfont-renderer.a
ARCHIVES	= $(XCERRCAL) $(LIBFT) $(MLX) $(MLXW) $(FONT_RENDER)

# Variables
DEBUG_MLXUI	= 4

ifeq ($(filter $(DEBUG_LVL),1 $(DEBUG_MLXUI)),)
DEBUG		= 0
else
DEBUG		= 1
endif
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

VARS		= DEBUG_LVL=$(DEBUG_LVL) \
			  MAX_WIDTH=$(MAX_WIDTH) \
			  MAX_HEIGHT=$(MAX_HEIGHT) \
			  WIDTH=$(WIDTH) \
			  HEIGHT=$(HEIGHT) \
			  PERF=$(PERF) \
			  FULLSCREEN=$(FULLSCREEN) \
			  RESIZEABLE=$(RESIZEABLE) \
			  WINDOWLESS=$(WINDOWLESS)

# Compiler and flags
CC			?= cc

CFLAGS		= -Wall -Wextra -Werror \
			  -std=gnu11

DFLAGS		= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS		= $(addprefix -I,$(INCLUDES))

LFLAGS		= -L$(FONT_RENDIR) \
			  -L$(MLXWDIR) \
			  -L$(LIBFTDIR) \
			  -L$(MLXDIR) \
			  -L$(XCERRCALDIR) \
			  -L$(NAME) \
			  -lfont-renderer -lmlx-wrapper -lmlx -lft -lxcerrcal \
			  -lXtst -lXext -lX11 -lXrandr -lm

VFLAGS		= $(addprefix -D ,$(VARS) DEBUG=$(DEBUG))

CFLAGS		+= $(INSPECT_FLAGS) $(PROFILE_FLAGS) $(FFLAGS) $(VFLAGS)

CF			= $(CC) $(CFLAGS) $(IFLAGS)

AR			= $(if $(findstring -flto,$(FFLAGS)),$(FAST_AR),$(STD_AR))
ARFLAGS		= rcs
RANLIB		= $(if $(findstring -flto,$(FFLAGS)),$(FAST_RANLIB),$(STD_RANLIB))

# VPATH
vpath %.h $(INCDLUDES)
vpath %.o $(OBJDIR) $(LIBFTDIR)/$(OBJDIR) $(XCERRCALDIR)/$(OBJDIR) \
	$(MLXWDIR)/$(OBJDIR) $(FONT_RENDIR)/$(OBJDIR)
vpath %.d $(DEPDIR) $(LIBFTDIR)/$(DEPDIR) $(XCERRCALDIR)/$(DEPDIR) \
	$(MLXWDIR)/$(DEPDIR) $(FONT_RENDIR)/$(DEPDIR)

# Sources
include $(SRCDIR)/srcs.mk

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.c=.d)))



all:	$(NAME)
fast:	$(NAME)
inspect:$(NAME)
profile:$(NAME)

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

.PHONY: all re debug redebug fast refast clean fclean help buildmsg print-%
