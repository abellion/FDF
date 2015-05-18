# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellion <abellion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 21:03:07 by abellion          #+#    #+#              #
#    Updated: 2015/03/15 17:37:20 by abellion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C =	gnl/get_next_line.c \
		program_files/src/main.c \
		program_files/src/args/args_controller.c \
		program_files/src/args/args_errors_printer.c \
		program_files/src/parser/parser_controller.c \
		program_files/src/parser/parser_lst_manager.c \
		program_files/src/env/env_controller.c \
		program_files/src/printer/printer_controller.c \
		program_files/src/printer/printer_calculator.c \
		program_files/src/printer/printer_utilities.c \
		program_files/src/printer/printer_line.c

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

SOFT_NAME = fdf

ARCHIVE_NAME = fdf.a

C_G = $(shell echo "\033[0;32m")

C_END = $(shell echo "\033[0m")

all: $(SOFT_NAME)

$(SOFT_NAME): $(SRC_C)
	make -C libft/
	@echo "\n$(C_G)	==========	SOFTWARE COMPILATION	==========$(C_END)"
	gcc -g -Wall -Wextra -Werror -I libft/includes/ -c $(SRC_C)
	@echo "\n$(C_G)	==========	CREATING ARCHIVE FILE	==========$(C_END)"
	ar rc $(ARCHIVE_NAME) $(OBJ)
	@echo "\n$(C_G)	==========	INDEXING ARCHIVE FILE	==========$(C_END)"
	ranlib $(ARCHIVE_NAME)
	@echo "\n$(C_G)	==========	CREATING EXECUTBLE FILE	==========$(C_END)"
	gcc -g -o $(SOFT_NAME) $(ARCHIVE_NAME) -L libft/ -lft -L/usr/X11/lib/ -lmlx -lXext -lX11

clean:
	make -C libft/ clean
	@echo "\n$(C_G)	==========	DELETING OBJECTS FILES	==========$(C_END)"
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	@echo "\n$(C_G)	==========	DELETING ARCHIVE FILE	==========$(C_END)"
	rm -rf $(ARCHIVE_NAME) $(SOFT_NAME)

re: fclean all
