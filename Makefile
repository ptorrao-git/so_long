# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 11:38:55 by ptorrao-          #+#    #+#              #
#    Updated: 2024/09/12 16:08:22 by ptorrao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE			= -I include
CC				= cc -g
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -fPIC
MLXFLAGS 		= -L minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
LIBFT			= libft/libft.a
MLX				= minilibx-linux/libmlx_Linux.a
NAME			= so_long
NAME_BONUS		= so_long_bonus

SRC				= src/so_long.c src/utils/free.c src/utils/init.c src/validations/validations.c \
				src/error_info/error.c src/error_info/error2.c src/validations/map_validations.c \
				src/validations/count.c src/error_info/error3.c src/render/render.c src/moves/keys.c
				
SRC_BONUS		= src_bonus/so_long_bonus.c src_bonus/utils/free_bonus.c src_bonus/utils/init_bonus.c src_bonus/validations/validations_bonus.c \
				src_bonus/error_info/error_bonus.c src_bonus/error_info/error2_bonus.c src_bonus/validations/map_validations_bonus.c \
				src_bonus/validations/count_bonus.c src_bonus/error_info/error3_bonus.c src_bonus/render/render_bonus.c src_bonus/moves/keys_bonus.c \
				src_bonus/validations/enemies_bonus.c src_bonus/moves/moves_validations_bonus.c src_bonus/render/load_images_bonus.c \
				src_bonus/validations/counter_bonus.c

OBJ 			= $(SRC:.c=.o)
OBJ_BONUS 		= $(SRC_BONUS:.c=.o)

all:			deps $(NAME)

bonus:			deps $(NAME_BONUS)

deps:			
				make -C libft
				make -C minilibx-linux

$(NAME):		$(OBJ) $(MLX) $(LIBFT)
				$(CC) -o $@ $(OBJ) -Llibft $(MLX) $(MLXFLAGS) -lft

$(NAME_BONUS):	$(OBJ_BONUS) $(MLX) $(LIBFT)
				$(CC) -o $@ $(OBJ_BONUS) -Llibft $(MLX) $(MLXFLAGS) -lft

%.o: 			%.c
				$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
				make -C libft

$(MLX):
				make -C minilibx-linux

clean:
				$(RM) $(OBJ)
				$(RM) $(OBJ_BONUS)
				make -C libft clean

fclean: 		clean
				$(RM) $(NAME)
				$(RM) $(NAME_BONUS)
				make -C libft fclean

re: 			fclean all

re_bonus: 		fclean bonus

download:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz

.PHONY: 		all clean fclean re
