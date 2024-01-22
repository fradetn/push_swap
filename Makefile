RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

OBJ_DIR = obj/
SRC_DIR = src/
LIBFT_DIR = libft/

NAME = push_swap
BONUS_NAME = checker
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(SRC_DIR)algo_next.c $(SRC_DIR)algo_utils.c $(SRC_DIR)algo.c \
	$(SRC_DIR)check_args.c $(SRC_DIR)ft_free.c $(SRC_DIR)ft_longatoi.c \
	$(SRC_DIR)ft_math.c $(SRC_DIR)moves.c $(SRC_DIR)pile_manager.c \
	$(SRC_DIR)push_swap.c $(SRC_DIR)push_swap_utils.c \
	$(SRC_DIR)push_swap_utils2.c

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))


SRC_BONUS = $(SRC_DIR)bonus_checker.c $(SRC_DIR)algo_next.c \
	$(SRC_DIR)algo_utils.c $(SRC_DIR)algo.c \
	$(SRC_DIR)check_args.c $(SRC_DIR)ft_free.c $(SRC_DIR)ft_longatoi.c \
	$(SRC_DIR)ft_math.c $(SRC_DIR)moves.c $(SRC_DIR)pile_manager.c \
	$(SRC_DIR)push_swap_utils.c $(SRC_DIR)push_swap_utils2.c

OBJ_BONUS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_BONUS))

all: $(NAME)

bonus:$(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT)
	@echo "$(YELLOW)Compilation du checker en cours..."
	@$(CC) -g $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN)Compilation terminée.\n"


$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)Compilation en cours..."
	@$(CC) -g $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilation terminée.\n"

$(OBJ_DIR):
	@echo "$(YELLOW)Création du répertoire $(OBJ_DIR)..."
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Création terminée.\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compilation de $<..."
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compilation terminée.\n"

$(LIBFT):
	@echo "$(YELLOW)Compilation de la libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)Compilation terminée.\n"

clean:
	@echo "$(RED)Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1

fclean: clean
	@echo "$(RED)Suppression de $(NAME)..."
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@echo "$(RED)Suppression de la libft...\n"
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re