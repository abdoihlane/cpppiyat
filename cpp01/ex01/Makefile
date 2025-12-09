
NAME = MOAR_BRAINS

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp  zombieHorde.cpp Zombie.cpp

CC = c++

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
