CC = cc

MAKE = make

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

NAME = push_swap

SRC = 	ft_stack.c\
		push_swap.c \
		ft_operations.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : $(LIBFT_HEADER)
	$(MAKE) -C libft

libft : $(LIBFT)

clean :
	$(RM) -f $(OBJ)
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY : all clean fclean re libft