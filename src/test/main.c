/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/04 12:28:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "lft_xcerrcal.h"
#include "mlxw_xcerrcal.h"
#include "mlx_wrapper.h"
#include "font_renderer.h"
#include "mlxui.h"
#include <stdio.h>
#include <unistd.h>

#define FONT_PATH "assets/JetBrainsMono-ExtraLight.ttf"
#define MEOW_PATH "assets/meow.pam"
#define BUG_PATH "assets/bug.ppm"

typedef struct s_env
{
	t_mlx	*mlx_data;
	t_htree	htree;
}	t_env;

t_hbranch	*button_group;

t_vec2i		start_pos = (t_vec2i){{0, 0}};
t_vec2i		end_pos = (t_vec2i){{0, 0}};

int	loop(t_env *env)
{
	ft_mlx_batch_put(&env->mlx_data->img, vec2i(0, 0), vec2i(WIDTH, HEIGHT), drgb_int(0x000000));
	render_hierarchy(&env->htree);
	if (start_pos.x != 0 && start_pos.y != 0)
		ft_mlx_select_put(&env->mlx_data->img, start_pos, end_pos, drgb_int(0xFFFFFF));
	mlx_put_image_to_window(env->mlx_data->mlx, env->mlx_data->win, env->mlx_data->img.img, 0, 0);
	return (0);
}

void	register_errors(void)
{
	register_lft_errors();
	register_mlxw_errors();
	register_frdr_errors();
}

void	select_zone(t_vec2i pos, t_maction action, void *arg, t_mlx *mlx_data)
{
	(void)mlx_data;
	(void)arg;
	if (action == MPRESS)
	{
		start_pos = pos;
		end_pos = pos;
	}
	else if (action == MRELEASE)
	{
		start_pos = vec2i(0, 0);
		end_pos = vec2i(0, 0);
	}
}

void    select_mouse_pos(void *v, t_mlx *mlx_data)
{
    (void)v;
    if (start_pos.x != 0 && start_pos.y != 0)
    	end_pos = vec2i(mlx_data->mouse_input.pos.x, mlx_data->mouse_input.pos.y);
}

int	add_mouse_hook(t_mlx *mlx_data)
{
	if (add_func_move_hook(mlx_data, select_mouse_pos, NULL) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_button_hook(mlx_data, MLCLICK, select_zone, NULL) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (0);
}


void	populate_tree(t_hbranch *hbranch, int depth)
{
	t_hbranch	*new;
	
	if (depth == 4)
		return ;
	else if (depth == 3)
	{
		new = add_checkbox(hbranch, NULL);
		new->x_pos_operation = center_screen;
		new->y_pos_operation = center_screen;
		new->checkbox.checked = ft_calloc(sizeof(bool), 1);
	}
	else
	{
		new = add_box(hbranch, (t_radius){.style = FULL_PX, .full = 20},
			(t_border){.size = 1, .color = hbranch->head->style.border, .style = SOLID});
		new->x_pos_operation = operation_half;
		new->y_pos_operation = operation_half;
		new->x_size_operation = operation_half;
		new->y_size_operation = operation_half;
		new->anchor = LT;
	}
	populate_tree(new, depth + 1);
}

t_hbranch	*add_text(t_hbranch *hbranch)
{
	t_hbranch	*text;

	text = add_textbox(hbranch,
	(t_text)
	{
		.content = "testallo?\nbonjours\no\noui",
		.font_size = 3,
		.fg = (t_rgba_int){.rgba=WHITE},
	},
	CENTER_ALIGN,
	NO_WRAPPING);
	text->textbox.vert_align = BASELINE_ALIGN;
	text->anchor = RIGHT;
	text->x_pos_operation = center_screen;
	text->y_pos_operation = center_screen;
	text->x_size_operation = operation_half;
	text->y_size_operation = operation_half;
	return (text);
}

t_hbranch	*add_form_test(t_hbranch *hbranch, int *test_val)
{
	t_hbranch	*form;

	form = add_form(hbranch, test_val, FORM_INT, "km");
	form->anchor = CENTER;
	form->x_pos_operation = center_screen;
	form->y_pos_operation = center_screen;
	form->form.is_valid_input = form_is_valid_input;
	form->form.format_buf = form_format_buf;
	form->form._btov = form_btov;
	form->form._vtob = form_vtob;
	return (form);
}

static inline void	test_button_action(t_hbranch *hbranch, void *arg)
{
	static int	feur = 0;

	(void)hbranch;
	(void)arg;
	feur++;
	printf("button pressed: %d\n", feur);
}

t_hbranch	*add_button_test(t_hbranch *hbranch)
{
	t_hbranch	*button;
	t_hbranch	*text;

	button = add_button(hbranch, (t_radius){.style = FULL_PX, .full = 12},
		(t_border){.size = 1, .color = hbranch->head->style.border, .style = SOLID});
	button->button.action = test_button_action;
	button->anchor = RB;
	button->pos = vec2i_sub_scalar(hbranch->head->mlx_data->size, 20);
	button->size = vec2i(80, 30);
	text = add_textbox(button,
	(t_text)
	{
		.content = "click me",
		.font_size = 2,
		.fg = (t_rgba_int){.rgba=WHITE},
	},
	CENTER_ALIGN,
	NO_WRAPPING);
	text->anchor = RB;
	text->x_pos_operation = copy;
	text->y_pos_operation = copy;
	text->x_size_operation = copy;
	text->y_size_operation = copy;
	return (button);
}

t_hbranch	*add_button_group_test(t_hbranch *hbranch)
{
	t_hbranch	*button;
	t_hbranch	*text;
	size_t		i;

	button_group = add_button_group(hbranch, GROUP_VERT, GROUP_SWITCH);
	button_group->anchor = RB;
	button_group->pos = vec2i(hbranch->head->mlx_data->size.x - 20, hbranch->head->mlx_data->size.y - 80);
	i = 0;
	while (i < 5)
	{
		button = add_button(button_group, (t_radius){},
					(t_border){.size = 1, .color = hbranch->head->style.border, .style = SOLID});
		button->button.action = test_button_action;
		button->size = vec2i(50, 50);

		text = add_textbox(button,
		(t_text)
		{
			.font_size = 3,
			.fg = (t_rgba_int){.rgba=WHITE},
		},
		CENTER_ALIGN,
		NO_WRAPPING);
		text->textbox.content[0] = '0' + (int)i;
		text->anchor = LT;
		text->x_pos_operation = copy;
		text->y_pos_operation = copy;
		text->x_size_operation = copy;
		text->y_size_operation = copy;
		i++;
	}
	return (button_group);
}

t_hbranch	*add_select_test(t_hbranch *hbranch)
{
	t_hbranch	*select;

	select = add_select(hbranch, "Select engine...");
	select->anchor = LT;
	select->pos = vec2i(20, hbranch->head->mlx_data->size.y / 2 + 40);
	add_select_option(select, "Wireframe", test_button_action);
	add_select_option(select, "Eevee", test_button_action);
	add_select_option(select, "Cycles", test_button_action);
	return (select);
}

t_hbranch	*add_image_test(t_hbranch *hbranch)
{
	t_hbranch	*meow;
	meow = add_image(hbranch, MEOW_PATH);
	meow->anchor = RT;
	meow->pos = vec2i(hbranch->head->mlx_data->size.x, 0);

	t_hbranch	*image1;
	image1 = add_image(hbranch, BUG_PATH);
	image1->anchor = LB;
	image1->pos = vec2i(0, hbranch->head->mlx_data->size.y);
	
	t_hbranch	*text;
	text = add_textbox(hbranch,
	(t_text)
	{
		.content = "are you\nserious?",
		.font_size = 3,
		.fg = (t_rgba_int){.rgba=WHITE},
	},
	CENTER_ALIGN,
	NO_WRAPPING);
	text->textbox.vert_align = BASELINE_ALIGN;
	text->anchor = RT;
	text->pos = vec2i(hbranch->head->mlx_data->size.x, meow->size.y - 55);
	text->size.x = meow->size.x;
	return (meow);
}

t_hbranch	*add_scrollbox_test(t_hbranch *hbranch)
{
	t_hbranch	*scrollbox;

	scrollbox = add_scrollbox(hbranch);
	scrollbox->pos = vec2i((float)hbranch->head->mlx_data->size.x / 1.6f, 10);
	scrollbox->anchor = TOP;
	scrollbox->scrollbox._current_pos = 0;

	t_hbranch	*meow;
	size_t		i = 0;
	while (i < 6)
	{
		meow = add_image(scrollbox->scrollbox.inside, MEOW_PATH);
		meow->anchor = LT;
		meow->pos = vec2i(0, meow->size.y * i);
		i++;
	}

	if (false)
	{
		t_hbranch	*select;
		select = add_select(scrollbox->scrollbox.inside, "Select engine...");
		select->anchor = LT;
		select->pos = scrollbox->scrollbox.inside->_lt;
		add_select_option(select, "Wireframe", test_button_action);
		add_select_option(select, "Eeveee", test_button_action);
		add_select_option(select, "Cycles", test_button_action);
	}
	scrollbox->size = vec2i(meow->size.x, meow->size.y * 1.75);
	scrollbox->scrollbox.inside->size = vec2i(meow->size.x, meow->size.y * i);
	return (scrollbox);
}

#define C_BACKGROUND              0xFF151417
#define C_FOREGROUND              0xFFFDFDFD

#define C_CARD                    0xFF222027

#define C_PRIMARY                 0xFFF7A83B
#define C_PRIMARY_FG              0xFFFCF2E8

#define C_SECONDARY               0xFF2F2C37
#define C_SECONDARY_FG            0xFFFDFDFD

#define C_MUTED                   0xFF2F2C37
#define C_MUTED_FG                0xFFB2B5D6

#define C_ACCENT                  0xFF2F2C37
#define C_ACCENT_FG               0xFFFDFDFD

#define C_DESTRUCTIVE             0xFFE25A2B
#define C_BORDER                  0x1AFFFFFF  // 10% opacity
#define C_INPUT                   0x26FFFFFF  // 15% opacity

void	test_htree(t_htree *htree, t_mlx *mlx_data, int *test_val)
{
	t_style	style = (t_style)
	{
		.radius = 9,
		.background = drgba_int(C_BACKGROUND),
		.foreground = drgba_int(C_FOREGROUND),
		.card = drgba_int(C_CARD),
		.primary = drgba_int(C_PRIMARY),
		.primary_fg = drgba_int(C_PRIMARY_FG),
		.secondary = drgba_int(C_SECONDARY),
		.secondary_fg = drgba_int(C_SECONDARY_FG),
		.muted = drgba_int(C_MUTED),
		.muted_fg = drgba_int(C_MUTED_FG),
		.accent = drgba_int(C_ACCENT),
		.accent_fg = drgba_int(C_ACCENT_FG),
		.destructive = drgba_int(C_DESTRUCTIVE),
		.border = drgba_int(C_BORDER),
		.input = drgba_int(C_INPUT),
	};
	*htree = init_htree(mlx_data, style);
	htree->body = ft_calloc(1, sizeof(t_hbranch));
	*(htree->body) = (t_hbranch)
	{
		.type = BOX,
		.visible = true,
		.rendered = true,
		.parent = NULL,
		.head = htree,
		.childs = ft_calloc(sizeof(t_vector), 1),
		.box = (t_box)
		{
			.img = &mlx_data->img,
			.precompute = precompute_box,
			.render = (void (*)(t_hbranch *, void *))render_box,
			.anchor = LT,
			.size = htree->mlx_data->size,
			.pos = vec2i(0, 0),
			.color = htree->style.background,
		},
	};
	htree->body->type = BOX;
	if (init_ttf(FONT_PATH, &htree->style.font) != 0)
		return ;
	if (true)
	{
		populate_tree(htree->body, 0);
		populate_tree(htree->body, 0);
		add_text(htree->body);
		add_form_test(htree->body, test_val);
		add_button_test(htree->body);
		add_button_group_test(htree->body);
		add_select_test(htree->body);
		add_image_test(htree->body);
	}
	add_scrollbox_test(htree->body);
	precompute_hierarchy(htree);
}


int	main(void)
{
	t_env	env;
	int		ret;
	int	test_val;

	test_val = 59;
	ret = 0;
	ft_bzero(&env, sizeof(t_env));
	register_errors();
	env.mlx_data = init_mlx(WIDTH, HEIGHT, "TEST");
	if (!env.mlx_data)
		ret = error(pack_err(MLXW_ID, MLXW_E_INITF), FL, LN, FC);
	ft_mlx_center_window(env.mlx_data);
	test_htree(&env.htree, env.mlx_data, &test_val);
	add_mouse_hook(env.mlx_data);
	start_mlx_loop(env.mlx_data, loop, &env);
	print_errs();
	return (ret);
}
