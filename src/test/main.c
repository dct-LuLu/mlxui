/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/25 23:38:43 by jaubry--         ###   ########.fr       */
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

#define FONT_PATH "/home/jaubry--/Documents/42/Minirt/asset/fonts/JetBrainsMono-ExtraLight.ttf"

typedef struct s_env
{
	t_mlx	*mlx_data;
	t_htree	htree;
}	t_env;

t_vec2i		start_pos = (t_vec2i){{0, 0}};
t_vec2i		end_pos = (t_vec2i){{0, 0}};

int	loop(t_env *env)
{
	ft_mlx_batch_put(&env->mlx_data->img, vec2i(0, 0), vec2i(WIDTH, HEIGHT), drgb_int(0x000000));
	render_hierarchy(&env->htree);
	if (start_pos.x != 0 && start_pos.y != 0)
		ft_mlx_select_put(&env->mlx_data->img, start_pos, end_pos, drgb_int(0xFFFFFF));
	mlx_put_image_to_window(env->mlx_data->mlx, env->mlx_data->win, env->mlx_data->img.img, 0, 0);
	//printf("key: %d\n", env->mlx_data->key_input.keycode);
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
    const t_mouse_event     mouse_event = (t_mouse_event)
    {
            .action = select_mouse_pos,
            .arg = NULL
    };
    vector_add(mlx_data->mouse_input.move_events, (void *)&mouse_event, 1);
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
				(t_border){.size = 1, .color = hbranch->head->style.outline, .style = SOLID});
		new->x_pos_operation = center_screen;
		new->y_pos_operation = center_screen;
		new->x_size_operation = operation_half;
		new->y_size_operation = operation_half;
	}
	populate_tree(new, depth + 1);
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
	text->anchor = CENTER;
	text->x_pos_operation = center_screen;
	text->y_pos_operation = center_screen;
	//text->x_pos_operation = operation_half;
	//text->y_pos_operation = operation_half;
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
	//form->x_size_operation = operation_half;
	//form->y_size_operation = operation_half;
	form->form.is_valid_input = form_is_valid_input;
	form->form.format_buf = form_format_buf;
	form->form._btov = form_btov;
	form->form._vtob = form_vtob;
	return (form);
}

void	test_htree(t_htree *htree, t_mlx *mlx_data, int *test_val)
{
	t_style	style = (t_style)
	{
		.color = rgba_int(30, 30, 30, 80),
		.outline = rgba_int(62, 62, 62, 230),
		.accent = rgba_int(56, 93, 209, 255),
		.text_fg = rgba_int(255, 255, 255, 255)
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
			.precompute = precompute_box,
			.render = (void (*)(t_hbranch *, void *))render_box,
			.anchor = LT,
			.size = vec2i_sub_scalar(htree->mlx_data->size, 50),
			.pos = vec2i(25, 25),
			.color = htree->style.color,
			.radius = (t_radius)
			{
				.style = FULL_PX,
				.full = 20
			},
			.border = (t_border)
			{
				.size = 1,
				.color = htree->style.outline,
				.style = SOLID
			}
		},
	};
	htree->body->type = BOX;
	if (init_ttf(FONT_PATH, &htree->style.font) != 0)
		return ;
	if (false)
	{
		populate_tree(htree->body, 0);
		populate_tree(htree->body, 0);
		add_text(htree->body);
	}
	add_form_test(htree->body, test_val);
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
