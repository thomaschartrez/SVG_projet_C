CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99 -fstack-protector -Iinlcude

SRC = 	src/main.c \
		src/add_to_file.c \
		src/create_forme.c \
		src/color.c \
		src/chain_list.c \
		src/all_free.c \
		src/init_node.c \
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