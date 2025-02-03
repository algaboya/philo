NAME = philo

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

SRC = main.c utils.c init.c\
		help.c simulation.c\
		set_get.c timing.c\
		acting.c val.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) philo.h Makefile
	cc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(BNOBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
