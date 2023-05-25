# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:20:57 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/05/25 14:43:52 by edufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

MLX = /mlx/libmlx.a
MLX_PATH = include/mlx/

GNL_SRC = include/get_next_line/get_next_line.c \
			include/get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

SRCS = srcs/main.c \
			srcs/check.c \
			srcs/checks_utils.c \
			srcs/check_utils_2.c \
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJS) $(GNL_OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -Imlx -o $@ $^ $(LIBFT) -L. -lmlx -framework OpenGL -framework AppKit

clean:
	@$(RM) $(OBJS) $(GNL_OBJ) 
	@make -C $(LIBFT_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) $(MLX) 

re:		fclean all