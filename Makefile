NAME = ft_printf.a
CC = cc;
HEADER = ft_printf.h
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_print_char.c ft_print_string.c ft_print_adress.c ft_print_decimal.c \
       ft_print_unsigned_decimal.c ft_print_lower_hex.c ft_print_upper_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
