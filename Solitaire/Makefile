##
## Makefile for test makefile in /home/cendri_a/Perso/fuck_it_c_cpp
## 
## Made by arthur cendrier
## Login   <cendri_a@epitech.net>
## 
## Started on  Thu Oct 15 20:31:24 2015 arthur cendrier
## Last update Sat Oct 17 18:15:00 2015 arthur cendrier
##

CC	=	g++

SRC	=	Card.cpp \
		MainApplication.cpp \
		main.cpp

CFLAGS	=	 -std=c++11

OBJ	=	$(SRC:.cpp=.o)

NAME	=	solitaire

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(CFLAGS)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
