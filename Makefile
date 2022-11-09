SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/parse.c \
	$(SRCS_DIR)/utils/utils_01.c \
	$(SRCS_DIR)/lists/listutils_01.c \
	$(SRCS_DIR)/lists/listutils_02.c \

SRCS_DIR = srcs

OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR = objs

FLAGS = -g -Wextra -Wall -Werror -fsanitize=address
CC = gcc
RM = rm -rf
NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJS_DIR)

re:	fclean all

.PHONY: clean all re fclean
