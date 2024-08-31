# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address,undefined

# Flags para readline
LDFLAGS += -L/opt/homebrew/opt/readline/lib
CPPFLAGS += -I/opt/homebrew/opt/readline/include

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft

# Source files
SRC_FILES := $(SRC_DIR)/main.c \
	$(SRC_DIR)/executor/assign_hdocs.c \
	$(SRC_DIR)/executor/counters.c \
	$(SRC_DIR)/executor/executor.c \
	$(SRC_DIR)/executor/expand_hdoc.c \
	$(SRC_DIR)/executor/expand_path.c \
	$(SRC_DIR)/executor/here_doc.c \
	$(SRC_DIR)/executor/set_redirections.c \
	$(SRC_DIR)/feature_test/test_expansor.c \
	$(SRC_DIR)/feature_test/test_splitted.c \
	$(SRC_DIR)/feature_test/test_lexer.c \
	$(SRC_DIR)/globals/prev_exit_status.c \
	$(SRC_DIR)/parsing/parse_str.c \
	$(SRC_DIR)/parsing/split_sh/split_sh.c \
	$(SRC_DIR)/parsing/split_sh/cmd_func.c \
	$(SRC_DIR)/parsing/split_sh/helper_str.c \
	$(SRC_DIR)/parsing/tokenizer/tokenizer.c \
	$(SRC_DIR)/parsing/expansor/expand_quotes.c \
	$(SRC_DIR)/parsing/expansor/expand_var.c \
	$(SRC_DIR)/parsing/expansor/expansor.c \
	$(SRC_DIR)/parsing/expansor/get_body.c \
	$(SRC_DIR)/parsing/expansor/get_prefix.c \
	$(SRC_DIR)/parsing/expansor/get_var_loc.c \
	$(SRC_DIR)/parsing/expansor/get_var_val.c \
	$(SRC_DIR)/parsing/expansor/insert.c \
	$(SRC_DIR)/parsing/expansor/protect_utils.c \
	$(SRC_DIR)/parsing/expansor/remove_protection.c \
	$(SRC_DIR)/parsing/expansor/set_limits.c \
	$(SRC_DIR)/parsing/lexer/check_input.c \
	$(SRC_DIR)/parsing/lexer/get_states.c \
	$(SRC_DIR)/builtins/builtins.c \
	$(SRC_DIR)/builtins/cd.c \
	$(SRC_DIR)/builtins/env.c \
	$(SRC_DIR)/builtins/exit.c \
	$(SRC_DIR)/builtins/pwd.c \
	$(SRC_DIR)/signals.c \

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(LIBFT_DIR) -lft -lreadline

# Executable
TARGET := minishell


all: libft $(TARGET)

# Libft targets
libft:
	$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean: libft_clean
	rm -rf $(OBJ_DIR)

fclean: clean libft_fclean
	rm -f $(TARGET)

re: fclean all

bonus:: CFLAGS += -D BONUS=1
bonus: re

rebonus: fclean bonus

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS)
# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re
