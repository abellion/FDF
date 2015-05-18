/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:01:52 by abellion          #+#    #+#             */
/*   Updated: 2015/03/15 17:03:15 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../../libft/includes/libft.h"

int		main(int ac, char **av)
{
	char			*file_name;
	t_coordinates	*coordinates;

	ac = 0;
	file_name = args_controller(av);
	coordinates = parser_controller(file_name);
	if (!coordinates)
		return (0);
	env_controller(coordinates);
	parser_lst_del(&coordinates);
	return (0);
}
