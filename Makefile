NAME = so_long
NAME_BONUS = so_long_bonus
MLX_LINK = -I. -I./minilibx_linux/ -L./minilibx-linux-lmlx -lX11 -lXext
MLX_LIB = ./minilibx-linux/libmlx.a
MLX_EX = $(MLX_LIB) $(MLX_LINK)
HEADER_DIR = ./includes/
HEADER = ./includes/so_long.h
HEADER_BONUS = ./includes/so_long_bonus.h
CFLAGS = -Wall -Werror -Wextra -I $(HEADER_DIR)
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

CFILES_BONUS = check_path_bonus.c\
	check_bonus.c\
	error_bonus.c\
	init_bonus.c\
	main_bonus.c\
	parse_map_bonus.c\
	utils_bonus.c\
	ft_split_bonus.c\
	render_bonus.c\
	itoa_bonus.c\
	input_bonus.c\
	exit_game_bonus.c\
	map_utils_bonus.c

SRCS_DIR = ./src/
OBJS_DIR = ./obj/

SRCS_DIR_BONUS = ./bonus/
OBJS_DIR_BONUS = ./obj_bonus/

SRCS = $(addprefix $(SRCS_DIR), $(CFILES))

OBJS = $(addprefix $(OBJS_DIR), $(CFILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR_BONUS), $(CFILES_BONUS:.c=.o))

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(MLX_EX) -o $(NAME)

$(NAME_BONUS): $(MLX_LIB) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(MLX_EX) -o $(NAME_BONUS)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c $(HEADER_BONUS)
	mkdir -p $(OBJS_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_DIR_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean
	make all

.PHONY: all clean fclean re bonus