NAME = so_long

CC = cc
HEADERS = ./libft/headers
CFLAGS = -Wall -Wextra -Werror -g -I$(HEADERS)
MLX_INCLUDE = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
AR = ar rc $(NAME)
RM = rm -f

RESET = $(shell tput sgr0)
BOLD_TEXT = $(shell tput bold)
ITALIC_TEXT = $(shell tput sitm)
COLOUR_BLUE = \033[0;34m
COLOUR_GREEN = \033[0;32m

LIBFT_MAKE = ./libft
MLX_MAKE = ./mlx

SRC = main.c \
		./src/check_map.c \
		./src/str_checks.c \
		./src/map_handling.c \
		./src/get_positions.c \
		./src/mtx_checks.c \
		./src/playability.c \
		./src/game_win_handling.c \
		./src/get_img.c \
		./src/init_game.c \
		./src/free_all.c \
		./src/key_hook.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@make all -s -C $(LIBFT_MAKE)
	@make all -s -C $(MLX_MAKE) 2>/dev/null 1>/dev/null
	$(CC) $(CFLAGS) -I. -I$(HEADERS) $(OBJ) $(MLX_INCLUDE) -L$(LIBFT_MAKE) -lft -o $(NAME)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) Run ./so_long so you can play how much you want to! $(RESET)"
	@echo "		$(COLOUR_GREEN) $(ITALIC_TEXT) $(BOLD_TEXT) You ready? $(RESET)"

clean:
	@make clean -s -C $(LIBFT_MAKE)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(NAME)

re: fclean all



# .SILENT:
.PHONY: all clean fclean re