##
## EPITECH PROJECT, 2023
## doom
## File description:
## Makefile
##

SRC	=	src/lib/my_str_to_word_array.cpp \
		src/lib/lib.cpp \
        src/lib/utils.cpp \
		src/draw/draw.cpp \
		src/draw/draw_wall.cpp \
		src/draw/points.cpp \
		src/move/move_player.cpp \
		src/move/move_player_body.cpp \
		src/move/move_player_view.cpp \
		src/move/move_strafe.cpp \
		src/parser/convert_dante_to_config.cpp \
		src/parser/parser.cpp \
		src/world_handler.cpp \
		src/reload_world.cpp \
		src/walls.cpp \
		src/sectors.cpp \
		src/set_ground_sky.cpp \
		example.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	idt1

CPPFLAGS	=	-Wall -Wextra -std=c++20

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lGL -lGLU -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
