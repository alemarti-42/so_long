# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 15:31:10 by alemarti          #+#    #+#              #
#    Updated: 2021/10/04 16:38:44 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c			\
				so_long_utils.c		\
				load_config.c		\
				map_utils.c			\
				game_destroy.c		\
				player_move.c		\
				sprites_utils.c		\
				draw_utils.c


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
			${CC} ${CFLAGS}  ${MLXFLAGS} ${OBJS} ${LIBFT} -o ${NAME} 

${LIBFT}:
			make -C ./libft/ libft.a


clean:
			@${RM} ${OBJS}
			@make -C ./libft/ clean


fclean:		clean
			@${RM} ${NAME}
			@make -C ./libft/ fclean

re:			fclean all

test:		test.out
test.out:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${DBFLAGS} ${MLXFLAGS} ${OBJS} ${LIBFT} -o test.out 

retest:		fclean test

PHONY:		all bonus clean fclean re