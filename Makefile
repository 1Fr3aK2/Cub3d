# -------------------
# ARQUIVOS E EXECUTÁVEL
# -------------------
SRCS = src/errors/errors.c\
		src/init/init.c\
		src/parsing/file/check_file.c\
		src/parsing/map/check_map/check_map.c\
		src/parsing/map/get_map/get_map.c\
		src/parsing/map/get_map/parse_map.c\
		src/parsing/map/init_map.c\
		src/utils/utils.c\
		src/textures/set_textures.c\
		src/main.c

NAME = Cub3d

# -------------------
# COMPILADOR E FLAGS
# -------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./includes
RM = rm -f

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# -------------------
# CORES
# -------------------
RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
RED     = \033[31m

# -------------------
# BIBLIOTECAS
# -------------------
LIBFT_DIR = ./libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./libraries/libft/get_next_line
GNL = $(GNL_DIR)/get_next_line

MLX_DIR = ./libraries/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_LINKS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

# -------------------
# REGRAS PRINCIPAIS
# -------------------
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(MLX) $(MLX_LINKS)
	@echo "$(GREEN)$(NAME) ready!$(RESET)"

# -------------------
# OBJETOS
# -------------------
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling $< ...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# -------------------
# LIBFT
# -------------------
$(LIBFT):
	@echo "$(YELLOW)Compiling LIBFT...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory >/dev/null 2>&1

# -------------------
# GET_NEXT_LINE
# -------------------
$(GNL):
	@echo "$(YELLOW)Compiling GNL...$(RESET)"
	@$(MAKE) -C $(GNL_DIR) --no-print-directory >/dev/null 2>&1

# -------------------
# MINILIBX
# -------------------
$(MLX):
	@echo "$(YELLOW)Compiling MLX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) all >/dev/null 2>&1

# -------------------
# LIMPEZA
# -------------------
clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory >/dev/null 2>&1
	@$(MAKE) -C $(GNL_DIR) clean --no-print-directory >/dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1
	@echo "$(RED)Objects and libraries cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory >/dev/null 2>&1
	@$(MAKE) -C $(GNL_DIR) fclean --no-print-directory >/dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1
	@echo "$(RED)$(NAME) removed!$(RESET)"

re: fclean all

# -------------------
# PHONY
# -------------------
.PHONY: all clean fclean re
