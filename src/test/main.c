/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/29 21:48:47 by jaubry--         ###   ########.fr       */
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
	return (0);
}

void	register_errors(void)
{
	register_lft_errors();
	register_mlxw_errors();
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

void	add_three(t_hbranch *branch, int depth)
{
	if (depth == 5)
		return ;
	depth += 1;
	add_three(add_branch(branch, false), depth);
	add_three(add_branch(branch, false), depth);
}

void	test_htree(t_htree *htree, t_mlx *mlx_data)
{
	*htree = init_htree(mlx_data);
	htree->body = ft_calloc(1, sizeof(t_hbranch));
	*htree->body = init_hbranch(htree, NULL, false);
	add_three(htree->body, 1);
	precompute_hierarchy(htree);
}


int	main(void)
{
	t_env	env;
	int		ret;

	ret = 0;
	ft_bzero(&env, sizeof(t_env));
	register_errors();
	env.mlx_data = init_mlx(WIDTH, HEIGHT, "TEST");
	if (!env.mlx_data)
		ret = error(pack_err(MLXW_ID, MLXW_E_INITF), FL, LN, FC);
	ft_mlx_center_window(env.mlx_data);
	test_htree(&env.htree, env.mlx_data);

	add_mouse_hook(env.mlx_data);

	start_mlx_loop(env.mlx_data, loop, &env);
	print_errs();
	return (ret);
}
