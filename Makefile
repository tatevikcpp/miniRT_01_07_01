NAME = miniRT

CC = cc

CFLAGS =   -Wall -Wextra -Werror   -g -fsanitize=address  -g3 -ggdb3

SRCS = $(wildcard ./src/*.c) 

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = $(wildcard ./src/*.h)

INCLUDES = -I./libft  -I./includes -I./getnextline -I/usr/include -Imlx_linux

ifeq ($(uname), Linux)
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

RM = rm -f

%.o: %.c  ${HEADER} Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(LIBFTPRINFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -o $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFTDIR)

$(GNL) :
	$(MAKE) -C $(GNLDIR)

$(LIBFTPRINFT) :
	$(MAKE) -C $(LIBFTPRINFTDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(GNLDIR)
	@$(MAKE) clean -C $(LIBFTPRINFTDIR)
	@$(RM) $(OBJS)

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