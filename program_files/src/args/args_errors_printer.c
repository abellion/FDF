/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_errors_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:16:32 by abellion          #+#    #+#             */
/*   Updated: 2015/01/07 15:53:54 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include "../../../libft/includes/libft.h"

void	args_errors_printer(t_error error)
{
	if (error.number == -1)
		ft_putstr_fd("usage : ./fdf file\n", 2);
	if (error.number == -2 && errno)
	{
		ft_putstr_fd(error.details, 2);
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}
