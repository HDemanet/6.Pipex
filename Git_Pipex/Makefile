# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdemanet <hdemanet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 17:48:53 by hdemanet          #+#    #+#              #
#    Updated: 2024/07/31 10:37:36 by hdemanet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = src/pipex.c src/utils.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft
# SANITIZE = -fsanitize=address
# LEAKS = -fsanitize=leak

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		${CC} ${OBJS} ${LIBFT} -o ${NAME}

all:	${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

# sanitize: ${OBJS}
# 	${CC} ${OBJS} ${CFLAGS} ${SANITIZE} libft/libft.a -o ${NAME}

# leak: ${OBJS}
# 	${CC} ${OBJS} ${CFLAGS} ${LEAKS} libft/libft.a -o ${NAME}

.PHONY: all clean fclean re debug sanitize leak