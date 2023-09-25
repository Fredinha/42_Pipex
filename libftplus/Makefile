# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 16:17:49 by fgomes-f          #+#    #+#              #
#    Updated: 2023/09/23 14:16:36 by fgomes-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT_1 = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_atoi.c ft_bzero.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strdup.c ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_calloc.c

LIBFT_2 = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c

LIBFT_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF = ft_printf.c function_c.c function_s.c function_d_i.c function_u.c function_x.c function_bigx.c function_p.c

GNL = get_next_line.c get_next_line_utils.c

EXTRA = ft_split_free.c ft_strclen.c

SRC = ${LIBFT_1} ${LIBFT_2} ${LIBFT_BONUS} ${PRINTF} ${GNL} ${EXTRA}

OBJS = ${SRC:.c=.o}

INCLUDE = -I .
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
