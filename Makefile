NAME	= push_swap

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

SRC_DIR = src

OBJ_DIR	= obj

SRCS	= $(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/init_stack.c \
		$(SRC_DIR)/operations/swap.c \
		$(SRC_DIR)/operations/push.c \
		$(SRC_DIR)/operations/rotate.c \
		$(SRC_DIR)/operations/reverse_rotate.c \
		$(SRC_DIR)/push_swap_utils.c \

OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFT	= libft
LIBFT_A = $(LIBFT)/libft.a
LIBFT_INC = -I$(LIBFT)
LIBFT_OBJS = $(LIBFT)/*.o

PRINTF	= printf
PRINTF_A = $(PRINTF)/libftprintf.a
PRINTF_INC = -I$(PRINTF)
PRINTF_OBJS = $(PRINTF)/*.o

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(PRINTF_INC) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT) 
	@$(MAKE) clean -C $(PRINTF)

fclean: clean
	$(RM) $(NAME) $(LIBFT_A) $(PRINTF_A)

re: fclean all

.PHONY: all clean fclean re