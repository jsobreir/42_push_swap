LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c utils.c moves.c stack.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

NAME = push_swap

MAKE_BONUS = make bonus

FLAGS = -Wall -Wextra -Werror -g -L$(LIBFT_DIR) -lft

CC = cc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

%.o: %.c $(HEADER)
	$(CC) -g -Wall -Wextra -Werror -c  $< -o $@

$(LIBFT):
	$(MAKE_BONUS) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all re clean fclean