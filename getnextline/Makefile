
NAME = libgnl.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}:${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re
