/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:35:29 by abellion          #+#    #+#             */
/*   Updated: 2015/01/18 17:13:57 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../fdf.h"

void	printer_x(t_coordinates *new_coordinates, t_env *env)
{
	t_coordinates	*prev;

	prev = NULL;
	while (new_coordinates)
	{
		if (prev && !next_line(prev) && !next_line(new_coordinates))
			printer_line(prev, new_coordinates, env);
		prev = new_coordinates;
		new_coordinates = new_coordinates->next;
	}
}

void	printer_y(t_coordinates *new_coordinates, t_env *env)
{
	int				width;
	t_coordinates	*tmp;

	width = line_width(new_coordinates);
	while (new_coordinates)
	{
		if (!next_line(new_coordinates))
		{
			tmp = jump_lst(new_coordinates, width);
			printer_line(new_coordinates, tmp, env);
		}
		else
			width = line_width(new_coordinates->next);
		new_coordinates = new_coordinates->next;
	}
}

int		printer_controller(t_env *env, t_coordinates *coordinates)
{
	t_coordinates	*new_coordinates;

	new_coordinates = printer_calculator(coordinates);
	printer_x(new_coordinates, env);
	printer_y(new_coordinates, env);
	parser_lst_del(&new_coordinates);
	return (0);
}
