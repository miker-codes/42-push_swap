NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC		= main.c \
		stack_utils.c \
		stack_utils2.c \
		swap_ops.c \
		push_ops.c \
		rotate_ops.c \
		reverse_ops.c \
		sort_simple.c \
		sort_radix.c \
		disorder.c \
		sort_chunks.c \
		dispatch.c \
		sort_insertion.c \
		bench.c \
		bench2.c

OBJS		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re