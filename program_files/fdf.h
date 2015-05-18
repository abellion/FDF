/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:45:20 by abellion          #+#    #+#             */
/*   Updated: 2015/01/18 17:19:17 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>

/*
**Declarations de structures
*/
typedef struct	s_error
{
	int						number;
	char					*details;
}				t_error;

typedef struct	s_coordinates
{
	int						x;
	int						y;
	int						z;
	struct s_coordinates	*next;
}				t_coordinates;

typedef struct	s_env
{
	void					*mlx;
	void					*win;
}				t_env;

typedef struct	s_group
{
	struct s_env			*env;
	struct s_coordinates	*coordinates;
}				t_group;

/*
**Prototypes gestion arguments
*/
char			*args_controller(char **args);
int				is_file(char *file_name);
void			args_errors_printer(t_error error);

/*
**Prototypes parser
*/
t_coordinates	*parser_lst_new(void);
t_coordinates	*parser_controller(char *file_name);
t_coordinates	*split(char *line, t_coordinates *coordinates);
t_coordinates	*put_coordinates(int x, int y, int z);
void			parser_lst_del(t_coordinates **coordinates);

/*
**Prototypes env
*/
t_env			*env_controller(t_coordinates *coordinates);
t_env			*init_env(void);
t_group			*init_group(void);
int				key_hook(int key_code);
int				expose_hook(t_group *group);

/*
**Prototypes printer
*/
int				printer_controller(t_env *env, t_coordinates *coordinates);
int				next_line(t_coordinates *coordinates);
t_coordinates	*printer_calculator(t_coordinates *coordinates);
void			printer_line(t_coordinates *a, t_coordinates *b, t_env *env);
int				line_width(t_coordinates *coordinates);
int				map_height(t_coordinates *coordinates);
t_coordinates	*jump_lst(t_coordinates *coordinates, int jump);
void			printer_x(t_coordinates *new_coordinates, t_env *env);
void			printer_y(t_coordinates *new_coordinates, t_env *env);

#endif
