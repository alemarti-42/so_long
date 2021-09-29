# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 15:31:10 by alemarti          #+#    #+#              #
#    Updated: 2021/09/27 15:39:56 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c \


OBJS		= ${SRCS:.c=.o}

LIBFT		= ./libft/libft.a

NAME		= so_long

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
DBFLAGS		= -g3 -fsanitize=address


all:		${NAME}

bonus:		all

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${MLXFLAGS} ${OBJS} ${LIBFT} -o ${NAME} 

${LIBFT}:
			make -C ./libft/ libft.a


clean:
			@${RM} ${OBJS}
			@make -C ./libft/ clean


fclean:		clean
			@${RM} ${NAME}
			@make -C ./libft/ fclean

re:			fclean all

PHONY:		all bonus clean fclean re