
NAME = ex00

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CC) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all
