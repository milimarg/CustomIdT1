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
		src/main.c \
		src/world_handler.c \
		src/reload_world.c \
		src/walls.c \
		src/sectors.c \
		src/set_ground_sky.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-idt1.a

GRAPHICS	=	-lGL -lGLU -lm -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
