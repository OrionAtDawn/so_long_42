# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:20:57 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/05/30 12:37:49 by edufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

MLX = /mlx/libmlx.a
MLX_PATH	=	mlx

SRCS = srcs/so_long.c \
			srcs/check.c \
			srcs/checks_utils.c \
			srcs/check_utils_2.c \
			srcs/mlx_utils.c \
			srcs/player_move.c \
			srcs/so_long_utils.c \
			srcs/images_manager.c \
			 
OBJS		= 	${SRCS:.c=.o}

.c.o:
				@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH) &> /dev/null
				$(CC) $(OBJS) $(LIBFT) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT)

re:		fclean all