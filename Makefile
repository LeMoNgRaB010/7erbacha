NAME      = push_swap
CC        = cc
# CFLAGS  = -Wall -Wextra -Werror
CFLAGS    =

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRC = main.c \
      algorithms/simple_algorithm.c \
      operations/algo_op.c \
      operations/algo_rotations.c \
      operations/stack_op.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re