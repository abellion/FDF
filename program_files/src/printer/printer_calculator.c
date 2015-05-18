/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:56:53 by abellion          #+#    #+#             */
/*   Updated: 2015/01/19 14:19:48 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../fdf.h"

t_coordinates	*relief_calculator(t_coordinates *coordinates)
{
	double			cte1;
	double			cte2;
	double			x;
	double			y;

	cte1 = 0.7;
	cte2 = 0.7;
	x = cte1 * coordinates->x * 35 - cte2 * coordinates->y * 35;
	y = coordinates->z * (-5) + (cte1 / 2) * coordinates->x * 35 +
		(cte2 / 2) * coordinates->y * 35;
	return (put_coordinates(x, y, coordinates->z));
}

t_coordinates	*screen_calculator(void)
{
	int				width;
	int				height;

	width = 1680 / 2;
	height = 150;
	return (put_coordinates(width, height, -1));
}

t_coordinates	*printer_calculator(t_coordinates *coordinates)
{
	t_coordinates	*new_coordinates;
	t_coordinates	*begin;
	t_coordinates	*screen;

	screen = screen_calculator();
	new_coordinates = put_coordinates(-1, -1, -1);
	begin = new_coordinates;
	while (coordinates)
	{
		if (!next_line(coordinates))
		{
			new_coordinates->next = relief_calculator(coordinates);
			new_coordinates->next->x += screen->x;
			new_coordinates->next->y += screen->y;
		}
		else
			new_coordinates->next = put_coordinates(-1, -1, -1);
		new_coordinates = new_coordinates->next;
		coordinates = coordinates->next;
	}
	return (begin->next);
}
