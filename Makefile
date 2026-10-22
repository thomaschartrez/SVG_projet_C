CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99 -fstack-protector -Iinclude

SRC = 	src/main.c \
		src/utils/add_to_file.c \
		src/create_forme/create_forme.c \
		src/create_forme/create_point.c \
		src/create_forme/create_line.c \
		src/create_forme/create_ellipse.c \
		src/create_forme/create_circle.c \
		src/create_forme/create_rectangle.c \
		src/create_forme/create_square.c \
		src/create_forme/create_polyline.c \
		src/utils/color.c \
		src/utils/print_forme.c \
		src/utils/chain_list.c \
		src/utils/all_free.c \
		src/utils/init_node.c \
		src/modify.c \
		src/charge_save.c \
		src/create_save.c \

OBJ_DIR = bin

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

NAME = projet

vpath %.c src src/utils src/create_forme

build: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)


.PHONY: build clean