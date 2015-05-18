/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:48:40 by abellion          #+#    #+#             */
/*   Updated: 2015/01/18 17:14:37 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../fdf.h"

int				next_line(t_coordinates *coordinates)
{
	if (!coordinates)
		return (0);
	if (coordinates->x == -1 && coordinates->y == -1 && coordinates->z == -1)
		return (1);
	return (0);
}

int				line_width(t_coordinates *coordinates)
{
	int			width;

	width = 0;
	while (!next_line(coordinates) && coordinates)
	{
		width++;
		coordinates = coordinates->next;
	}
	return (width);
}

t_coordinates	*jump_lst(t_coordinates *coordinates, int jump)
{
	int				i;
	int				line;

	line = 0;
	i = 0;
	while (i <= jump && coordinates)
	{
		if (next_line(coordinates))
			line++;
		i++;
		coordinates = coordinates->next;
	}
	if (!coordinates || line > 1 || next_line(coordinates))
		return (0);
	return (coordinates);
}
