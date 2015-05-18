/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:15:11 by abellion          #+#    #+#             */
/*   Updated: 2015/01/07 15:54:49 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include "../../../libft/includes/libft.h"

int		is_file(char *file_name)
{
	if (open(file_name, O_WRONLY) == -1)
		return (0);
	return (1);
}

char	*args_controller(char **args)
{
	t_error		error;

	if (!args || !args[1])
	{
		error.number = -1;
		args_errors_printer(error);
		return (0);
	}
	if (!is_file(args[1]))
	{
		error.number = -2;
		error.details = args[1];
		args_errors_printer(error);
		return (0);
	}
	return (args[1]);
}
