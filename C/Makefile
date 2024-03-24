##
## EPITECH PROJECT, 2023
## doom
## File description:
## Makefile
##

SRC	=	src/lib/my_str_to_word_array.c \
		src/lib/lib.c \
        src/lib/utils.c \
		src/draw/draw.c \
		src/draw/draw_wall.c \
		src/draw/points.c \
		src/move/move_player.c \
		src/move/move_player_body.c \
		src/move/move_player_view.c \
		src/move/move_strafe.c \
		src/parser/convert_dante_to_config.c \
		src/parser/parser.c \
		src/world_handler.c \
		src/reload_world.c \
		src/walls.c \
		src/sectors.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libidt1.so

CFLAGS	=	-Wall -Wextra -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	gcc -shared -o $(NAME) $(OBJ) -lm -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
