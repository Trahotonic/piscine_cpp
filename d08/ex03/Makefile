CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = mindopen

SRC = AInstruction.cpp Increment.cpp Decrement.cpp GoBack.cpp GoFront.cpp NextBox.cpp PrevBox.cpp Print.cpp Machine.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@ $(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all
