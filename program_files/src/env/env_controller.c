/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:13:48 by abellion          #+#    #+#             */
/*   Updated: 2015/03/15 20:13:38 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include "../../../libft/includes/libft.h"

t_env		*init_env(void)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	return (env);
}

t_group		*init_group(void)
{
	t_group		*group;

	if (!(group = (t_group *)malloc(sizeof(t_group))))
		return (0);
	return (group);
}

int			key_hook(int key_code)
{
	if (key_code == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

int			expose_hook(t_group *group)
{
	printer_controller(group->env, group->coordinates);
	return (0);
}

t_env		*env_controller(t_coordinates *coordinates)
{
	t_env		*env;
	t_group		*group;

	if (!(env = init_env()))
		return (0);
	if (!(group = init_group()))
		return (0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1680, 1000, "Fil De Fer");
	group->env = env;
	group->coordinates = coordinates;
	mlx_key_hook(env->win, key_hook, &env);
	mlx_expose_hook(env->win, expose_hook, group);
	mlx_loop(env->mlx);
	return (env);
}
