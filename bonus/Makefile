NAME = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = ../libft/libft.a

SRCS = so_long_bonus.c parser_bonus.c tools_bonus.c tools2_bonus.c\

OBJS = $(SRCS:.c=.o)

MLX_API = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS) so_long_bonus.h
	@cc $(CFLAGS) $(MLX_API) $(OBJS) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@