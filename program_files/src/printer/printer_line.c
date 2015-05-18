/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 19:46:06 by abellion          #+#    #+#             */
/*   Updated: 2015/04/01 15:26:46 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../fdf.h"

void	printer_line_y(t_env *env, t_coordinates *begin, t_coordinates *end)
{
	int		x;
	int		y;
	int		cumul;
	int		i;

	cumul = abs(begin->x - end->x) / 2;
	x = begin->x;
	y = begin->y;
	i = 0;
	while (i < abs(begin->x - end->x))
	{
		cumul += abs(begin->y - end->y);
		if (cumul >= abs(begin->x - end->x))
		{
			cumul -= abs(begin->x - end->x);
			y += (end->y - begin->y > 0) ? 1 : -1;
		}
		x += (end->x - begin->x > 0) ? 1 : -1;
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
		i++;
	}
}

void	printer_line_x(t_env *env, t_coordinates *begin, t_coordinates *end)
{
	int		x;
	int		y;
	int		cumul;
	int		i;

	cumul = abs(begin->y - end->y) / 2;
	x = begin->x;
	y = begin->y;
	i = 0;
	while (i < abs(begin->y - end->y))
	{
		cumul += abs(begin->x - end->x);
		if (cumul >= abs(begin->y - end->y))
		{
			cumul -= abs(begin->y - end->y);
			x += (end->x - begin->x > 0) ? 1 : -1;
		}
		y += (end->y - begin->y > 0) ? 1 : -1;
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
		i++;
	}
}

void	printer_line(t_coordinates *a, t_coordinates *b, t_env *env)
{
	if (a && b && env)
	{
		if (abs(a->x - b->x) > abs(a->y - b->y))
			printer_line_y(env, a, b);
		else
			printer_line_x(env, a, b);
	}
}
