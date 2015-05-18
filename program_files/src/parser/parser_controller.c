/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:13:01 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 19:37:55 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include "../../../gnl/get_next_line.h"
#include "../../../libft/includes/libft.h"

t_coordinates	*split(char *line, t_coordinates *coordinates)
{
	char			**splits;
	int				x;
	static int		y;

	x = 0;
	y = (!y) ? 0 : y;
	splits = ft_strsplit(line, ' ');
	while (*splits)
	{
		coordinates->next = put_coordinates(x, y, ft_atoi(*splits));
		coordinates = coordinates->next;
		x++, splits++;
	}
	return (y++, coordinates);
}

t_coordinates	*parser_controller(char *file_name)
{
	int				fd;
	int				ret;
	char			*line;
	t_coordinates	*coordinates;
	t_coordinates	*begin;

	if (!file_name || !(fd = open(file_name, O_RDONLY)))
		return (0);
	coordinates = put_coordinates(-1, -1, -1);
	begin = coordinates;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		coordinates = split(line, coordinates);
		coordinates->next = put_coordinates(-1, -1, -1);
		coordinates = coordinates->next;
		free(line);
	}
	close(fd);
	return (begin->next);
}
