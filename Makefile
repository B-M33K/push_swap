CC = cc

MAKE = make
# VPATH = ./mandatory:./bonus

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

NAME = push_swap

CHECKER = checker

SRC = 	ft_utils1.c \
		ft_utils2.c \
		ft_utils3.c \
		ft_utils4.c \
		ft_utils5.c \
		ft_utils6.c

MAN_OBJ = push_swap.o
BON_OBJ = checker.o

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(MAN_OBJ) $(LIBFT)
	$(CC) $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : $(LIBFT_HEADER)
	$(MAKE) -C libft

libft : $(LIBFT)

bonus : $(CHECKER)

$(CHECKER) : $(OBJ) $(BON_OBJ) $(LIBFT)
	$(CC) $^ -o $@

clean :
	$(RM) -f $(OBJ) $(MAN_OBJ) $(BON_OBJ)
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY : all clean fclean re libft bonus