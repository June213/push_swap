NAME	= push_swap

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

SRCS	= push_swap.c \
		manage_argument.c

OBJS    = $(SRCS:.c=.o)

LIBFT	= libft
LIBFT_A = $(LIBFT)/libft.a
LIBFT_INC = -I$(LIBFT)
LIBFT_OBJS = $(LIBFT)/*.o

PRINTF	= printf
PRINTF_A = $(PRINTF)/libftprintf.a
PRINTF_INC = -I$(PRINTF)
PRINTF_OBJS = $(PRINTF)/*.o

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT) 
	$(MAKE) clean -C $(PRINTF)

fclean: clean
	$(RM) $(NAME) $(LIBFT_A) $(PRINTF_A)

re: fclean all

.PHONY: all clean fclean re