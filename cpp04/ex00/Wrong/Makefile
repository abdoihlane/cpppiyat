NAME := WrongAnimal

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := WrongMain.cpp WrongAnimal.cpp WrongDog.cpp WrongCat.cpp
OBJS := $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
