NAME = so_long

MLX_LINK = -I. -I./minilibx_linux/ -L./minilibx-linux-lmlx -lX11 -lXext
MLX_LIB = ./minilibx-linux/libmlx.a
MLX_EX = $(MLX_LIB) $(MLX_LINK)

CFLAGS = -Wall -Werror -Wextra -I ./includes/
CFILES = check_path.c\
	check.c\
	error.c\
	init.c\
	main.c\
	parse_map.c\
	utils.c\
	ft_split.c\
	render.c\
	itoa.c\
	input.c\
	exit_game.c\
	map_utils.c

SRCS_DIR = ./src/
OBJS_DIR = ./obj/

SRCS = $(addprefix $(SRCS_DIR), $(CFILES))

OBJS = $(addprefix $(OBJS_DIR), $(CFILES:.c=.o))

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) -g3 $(MLX_EX) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re