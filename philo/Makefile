NAME = philo

CFLAGS = -Wall -Wextra -Werror

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










# NAME = philo

# CFLAGS = -Wall -Wextra -Werror

# SRC = main.c

# OBJ = $(SRC:.c=.o)

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# all: $(NAME)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(NAME): $(OBJ) $(LIBFT) philo.h Makefile
# 	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# clean:
# 	rm -f $(OBJ)
# 	make -C $(LIBFT_DIR) clean

# fclean: clean
# 	rm -f $(NAME)
# 	make -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re

