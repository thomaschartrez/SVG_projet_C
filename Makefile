CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99 -fstack-protector

SRC = 	src/main.c \
		src/create.c \
		src/color.c \

OBJS = $(SRC:.c=.o)

NAME = projet

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re