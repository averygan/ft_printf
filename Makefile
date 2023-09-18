# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:37:38 by agan              #+#    #+#              #
#    Updated: 2023/09/12 14:37:46 by agan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_helper.c ft_printf.c ft_numbers.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
LIBC	= ar rc
CC	= gcc
RM	= rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean alls
