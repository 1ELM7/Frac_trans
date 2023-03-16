# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmendez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:21:30 by jmendez           #+#    #+#              #
#    Updated: 2023/03/03 16:54:49 by jmendez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -g -Wall -Werror -Wextra #-Ofast
LFLAGS = -L include/mlx_linux -lmlx -lXext -lX11 -L include/libft -lft -L include/ft_printf -lftprintf

SRC =   fractol.c  \
		colors.c    \
		colors_bis.c \
		draw_fract.c  \
		keys.c		   \
		utils.c		    \
		dispatch_colors.c\

OBJ = ${SRC:.c=.o}

CC = gcc

.c.o:
	@${CC} -g ${LFLAGS} ${CFLAG} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C include/libft --no-print-directory
	@make -C include/ft_printf --no-print-directory
	@make -C include/mlx_linux --no-print-directory
	@${CC} -o ${NAME} ${OBJ} ${LFLAGS} ${CFLAGS}
	@printf "The program is compiled\n"

all: ${NAME}

clean:
	@rm -f ${OBJ}
	@make clean -C include/libft --no-print-directory
	@printf "The program is clean and still got it executable fractol\n"

fclean: clean
	@rm -f ${NAME}
	@make fclean -C include/libft --no-print-directory
	@printf "The program is all clean\n"

re: fclean all
	@printf "The program cleaned and compiled again the executable fractol\n"

.PHONY : all clean fclean re
