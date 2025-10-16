# -------------------
# ARQUIVOS E EXECUTÁVEL
# -------------------
SRCS = src/main.c          # Adicione aqui todos os seus arquivos .c
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

MLX_DIR = ./libraries/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_LINKS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

# -------------------
# REGRAS PRINCIPAIS
# -------------------
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_LINKS)
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
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1
	@echo "$(RED)Objects and libraries cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory >/dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1
	@echo "$(RED)$(NAME) removed!$(RESET)"

re: fclean all

# -------------------
# PHONY
# -------------------
.PHONY: all clean fclean re
