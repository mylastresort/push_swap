CC=cc

FLAGS=-Wall -Wextra -Werror

NAME=push_swap
NAME_BONUS=checker

SRC= main.c deque_methods.c deque.c helpers.c operations.c sort_utils.c sort.c write_functions.c

OBJS:=$(SRC:.c=.o)

SRC_BONUS= checker_bonus.c checker_utils_bonus.c deque_methods.c deque.c helpers.c operations.c sort_utils.c sort.c write_functions.c

OBJS_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o checker