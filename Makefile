NAME = miniRT

CC = cc

CFLAGS =      -g -fsanitize=address  -g3 -ggdb3 -Wall -Wextra -Werror

SRCS = $(wildcard ./src/*.c) 

OBJS = $(patsubst ./src/%.c, $(DIROBJS)/%.o, $(SRCS))

DIROBJS = ./src/objs

HEADER = $(wildcard ./includes/*.h)

INCLUDES = -I./libft  -I./includes -I./getnextline -I/usr/include -Imlx_linux

ifeq ($(shell uname), Linux)
LINKERS	= -L./libft -lft  -L./getnextline -lgnl  -L./ft_printf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
LINKERS	= -L./libft -lft  -L./getnextline -lgnl  -L./ft_printf -lftprintf -lmlx -framework OpenGL -framework Appkit
endif

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

LIBFTPRINFT = ./ft_printf/libftprintf.a

LIBFTPRINFTDIR = ./ft_printf

GNL = ./getnextline/libgnl.a

GNLDIR = ./getnextline

RM = rm -fr

$(DIROBJS)/%.o: src/%.c  ${HEADER} Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

all: $(DIROBJS) $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(LIBFTPRINFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -o $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFTDIR)

$(GNL) :
	$(MAKE) -C $(GNLDIR)

$(LIBFTPRINFT) :
	$(MAKE) -C $(LIBFTPRINFTDIR)

$(DIROBJS) :
	mkdir $(DIROBJS)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(GNLDIR)
	@$(MAKE) clean -C $(LIBFTPRINFTDIR)
	@$(RM) $(OBJS)
	@$(RM) $(DIROBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(GNLDIR)
	@$(MAKE) fclean -C $(LIBFTPRINFTDIR)
	@$(RM) $(NAME)
	@echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

re: fclean all

norm:
	@norminette $(SRCS)

.PHONY: all clean fclean re