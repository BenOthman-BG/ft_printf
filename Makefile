NAME = libftprintf.a
CC = cc
HEADER = ft_printf.h
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_dispatch.c ft_print_text.c ft_print_nums.c ft_print_hex.c

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
