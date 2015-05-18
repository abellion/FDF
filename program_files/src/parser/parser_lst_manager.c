/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:15:31 by abellion          #+#    #+#             */
/*   Updated: 2015/01/18 17:13:14 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include "../../../libft/includes/libft.h"

t_coordinates	*put_coordinates(int x, int y, int z)
{
	t_coordinates	*coordinate;

	coordinate = parser_lst_new();
	coordinate->x = x;
	coordinate->y = y;
	coordinate->z = z;
	return (coordinate);
}

t_coordinates	*parser_lst_new(void)
{
	t_coordinates	*link;

	if (!(link = malloc(sizeof(t_coordinates))))
		return (0);
	link->x = 0;
	link->y = 0;
	link->z = 0;
	link->next = NULL;
	return (link);
}

void			parser_lst_del(t_coordinates **coordinates)
{
	t_coordinates	*tmp;

	while (*coordinates)
	{
		tmp = (*coordinates)->next;
		free(*coordinates);
		*coordinates = NULL;
		(*coordinates) = tmp;
	}
}
