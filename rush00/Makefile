CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra
NC = -lncurses
C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

NAME = ft_retro

SRC = Drop.class.cpp Shot.class.cpp Ship.class.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CXX) $(CXXFLAGS) $(NC) -o $(NAME) $(OBJ)
	@printf "$(C_MAGENTA)FT_RETRO:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

%.o: %.cpp
	@ $(CXX) $(CXXFLAGS) -o $@ -c $<
	@printf "$(C_MAGENTA)FT_RETRO:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@ rm -rf $(OBJ)
	@printf "$(C_MAGENTA)FT_RETRO:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@ rm -rf $(NAME)
    @printf "$(C_MAGENTA)FT_RETRO:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@
re: fclean all
