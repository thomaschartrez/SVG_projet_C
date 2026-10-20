CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99 -fstack-protector -Iinlcude

SRC = 	src/main.c \
		src/utils/add_to_file.c \
		src/create_forme/create_forme.c \
		src/create_forme/create_point.c \
		src/create_forme/create_line.c \
		src/create_forme/create_ellipse.c \
		src/create_forme/create_circle.c \
		src/create_forme/create_rectangle.c \
		src/create_forme/create_square.c \
		src/utils/color.c \
		src/utils/print_forme.c \
		src/utils/chain_list.c \
		src/utils/all_free.c \
		src/utils/init_node.c \
		src/modify.c \
		src/charge_save.c \
		src/create_save.c \

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