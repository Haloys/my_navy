##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME 	= my_radar

RM	= rm -f

MAKE 	= make

OBJ	= $(SRC:.c=.o)

INCLUDE = -I ./include/

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB = -L ./lib/my/ -lmy

SRC =	src/main.c				\
	src/utils.c				\
	src/entity_management.c			\
	src/init_cleanup.c			\
	src/parsing_utils.c			\
	src/script_parsing.c			\
	src/entity_updating.c			\
	src/event_handling.c			\
	src/game_loop.c				\
	src/rendering.c				\
	src/collision.c				\
	src/timer.c				\
	src/render_hitbox.c			\
	src/collision_handling.c		\
	src/init_entity.c			\
	src/menu_setup.c			\
	src/menu_control.c			\
	src/game_display.c

all: $(NAME)

$(NAME):
	cd lib/my && $(MAKE)
	gcc $(SRC) -o $(NAME) $(INCLUDE) $(CSFML) $(LIB) -lm

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
