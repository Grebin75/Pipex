SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/parse.c \
	$(SRCS_DIR)/utils/utils_01.c \
	$(SRCS_DIR)/lists/listutils_01.c \
	$(SRCS_DIR)/lists/listutils_02.c \

SRCS_DIR = srcs

OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR = objs

FLAGS = -g -Wextra -Wall -Werror #-fsanitize=address
CC = gcc
RM = rm -rf
NAME = pipex
PRINTF		= printf/libftprintf.a

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
		@echo
		@echo "$(CYAN)  _____ _____ _____  ________   __"
		@echo " |  __ \_   _|  __ \|  ____\ \ / /"
		@echo " | |__) || | | |__) | |__   \ V / "
		@echo " |  ___/ | | |  ___/|  __|   > <  "
		@echo " | |    _| |_| |    | |____ / . \ "
		@echo " |_|   |_____|_|    |______/_/ \_\ "
		@echo
		@echo
		@$(CC) $(FLAGS) $(OBJS) -Lprintf -lftprintf -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		@echo -n "$(RED)"
		@mkdir -p $(@D)
		$(CC) $(FLAGS) -c $< -o $@
		@echo -n "$(DEFAULT)"

$(PRINTF):
		@echo -n "$(YELLOW)"
		@echo "\nPRINTF:"
		@make --no-print-directory -C printf
		@echo -n "$(DEFAULT)"

clean:
		@$(RM) $(OBJS_DIR)
		@echo "$(CYAN)Cleaning Objects...$(DEFAULT)"
		@make --no-print-directory clean -C printf
fclean: clean
		@$(RM) $(NAME)
		@make --no-print-directory fclean -C printf
re:	fclean all

.PHONY: clean all re fclean
