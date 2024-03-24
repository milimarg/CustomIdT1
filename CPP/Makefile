##
## EPITECH PROJECT, 2023
## doom
## File description:
## Makefile
##

SRC	=	src/lib/lib.cpp \
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
		../tests/test.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	idt1

CPPFLAGS	=	-Wall -Wextra

GRAPHICS_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(GRAPHICS_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
