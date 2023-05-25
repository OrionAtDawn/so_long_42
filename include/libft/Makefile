# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 10:57:31 by edufour           #+#    #+#              #
#    Updated: 2023/05/25 15:56:07 by edufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# -------------------------------------------#
#				VARIABLES					 #
#--------------------------------------------#
NAME			=	libft.a
CC				=	gcc -c
RM 				= 	rm -f
CFLAGS			=	-Wall -Werror -Wextra

SRCS	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_isspace.c \
			ft_sizenb.c \
			ft_safe_free.c \
			ft_count_char_line.c \
			get_next_line.c \
			get_next_line_utils.c \
			

OBJCTS	=	$(SRCS:.c=.o)

B_SRC	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

B_OBJC	=	$(B_SRC:.c=.o)
#-------------------------------------------#
#				  RULES						#
#-------------------------------------------#

$(NAME) : $(OBJCTS)
	ar -rcs $(NAME) $(OBJCTS)

$(OBJCTS) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

bonus : $(B_OBJC)
	ar -rcs $(NAME) $(B_OBJC)

$(B_OBJC) : $(B_SRC)
	$(CC) $(CFLAGS) $(B_SRC)

clean :
	$(RM) $(OBJCTS) $(B_OBJC)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus