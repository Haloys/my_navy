##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Lib
##

SRC 	= 	my_put_nbr.c 		\
		my_putchar.c 		\
		my_putstr.c 		\
		my_strcat.c 		\
		my_strcpy.c 		\
		my_strlen.c 		\
		my_strcmp.c 		\
		my_getnbr.c		\
		mini_printf.c		\
		my_long_to_string.c	\
		my_digit_to_str.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I../../include

HEADER_N = my.h

LIB_N = libmy.a

CC = gcc

RM = rm -f

all: $(LIB_N)

$(LIB_N): $(OBJ)
	$(CC) -c $(OBJ)
	ar rc $(LIB_N) $(OBJ)
	cp $(LIB_N) ../$(LIB_N)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
