SRC =	ft_print_chars.c \
		ft_print_nums.c \
		ft_printf.c \


OBJ = ${SRC:.c=.o}
DEPS = ${SRC:.c=.d}

NAME = libftprintf.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -MMD

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rcs ${NAME} ${OBJ}

-include ${DEPS}

clean:
			${RM} ${OBJ} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clear fclean re
