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

BON = fractol_bonus

CFLAGS = -g -Wall -Werror -Wextra #-Ofast
LFLAGS = -L include/mlx_linux -lmlx -lXext -lX11 -L include/libft -lft -L include/ft_printf -lftprintf

SRC =   src/fractol.c  \
		src/colors.c    \
		src/colors_bis.c \
		src/draw_fract.c  \
		src/keys.c		   \
		src/utils.c		    \
		src/dispatch_colors.c

BONUS =	bonus/fractol_bonus.c  \
		bonus/colors_bonus.c    \
		bonus/colors_bis_bonus.c \
		bonus/draw_fract_bonus.c  \
		bonus/keys_bonus.c		   \
		bonus/utils_bonus.c		    \
		bonus/dispatch_colors_bonus.c

OBJ = ${SRC:src/%.c=obj/%.o}
OBJ_BONUS = ${BONUS:bonus/%.c=obj_bonus/%.o}

CC = gcc

obj/%.o: src/%.c
	@${CC} -g ${LFLAGS} ${CFLAG} -c $^ -o ${<:src/%.c=obj/%.o}

obj_bonus/%.o: bonus/%.c
	@${CC} -g ${LFLAGS} ${CFLAG} -c $^ -o ${<:bonus/%.c=obj_bonus/%.o}

OBJ_DIR = obj

BONUS_OBJ_DIR = obj_bonus

${NAME}: $(OBJ_DIR) ${OBJ}
	@make -C include/libft --no-print-directory
	@make -C include/ft_printf --no-print-directory
	@make -C include/mlx_linux --no-print-directory
	@${CC} -o ${NAME} ${OBJ} ${LFLAGS} ${CFLAGS}
	@printf "The program is compiled\n"

$(OBJ_DIR):
		mkdir $@

$(BONUS_OBJ_DIR):
		mkdir $@

${BON}: $(BONUS_OBJ_DIR) ${OBJ_BONUS}
	@make -C include/libft --no-print-directory
	@make -C include/ft_printf --no-print-directory
	@make -C include/mlx_linux --no-print-directory
	@${CC} -o ${BON} ${OBJ_BONUS} ${LFLAGS} ${CFLAGS}
	@printf "The program bonus is compiled\n"

all: ${NAME}

bonus: ${BON}

clean:
	@rm -f ${OBJ} ${OBJ_BONUS}
	@make clean -C include/libft --no-print-directory
	@make clean -C include/ft_printf --no-print-directory
	@make clean -C include/mlx_linux --no-print-directory
	@printf "The program is clean and still got it executable fractol\n"

fclean: clean
	@rm -f ${NAME} ${BON}
	@make fclean -C include/libft --no-print-directory
	@make fclean -C include/ft_printf --no-print-directory
	@make clean -C include/mlx_linux --no-print-directory
	@printf "The program is all clean\n"

re: fclean all
	@printf "The program cleaned and compiled again the executable fractol\n"

.PHONY : all bonus clean fclean re
