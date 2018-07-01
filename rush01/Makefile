# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 19:50:53 by snikitin          #+#    #+#              #
#    Updated: 2018/07/01 12:01:35 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_gkrellm

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
FRM_DIR := ./frm/

SRC :=  main.cpp\
        HostModule.class.cpp\
        CpuModule.class.cpp\
        Controller.class.cpp\
        NetModule.class.cpp\
        RamModule.class.cpp\
        ShellUI.class.cpp\
        GraphicalUI.class.cpp\
        IMonitorModule.cpp\

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.cpp=.o)))

INC =	$(INC_DIR)GraphicalUI.class.hpp\
		$(INC_DIR)IMonitorDisplay.class.hpp\
		$(INC_DIR)ShellUI.class.hpp\

SDL = $(SDL_DIR)SDL2
SDL_DIR = $(FRM_DIR)SDL2.framework/
SDL_INC = $(SDL_DIR)Headers/
SDL_FLAGS = $(SDL) -rpath $(FRM_DIR)

LINK_FLAGS = -lncurses $(SDL_FLAGS)
CC_FLAGS := -std=c++98 -pedantic -Wall -Wextra -Werror
HEADER_FLAGS := -I $(INC_DIR) -I $(SDL_INC)

CC := clang++

all: $(NAME)

$(NAME): $(OBJ) $(INC) Makefile
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)/*/%.cpp $(INC)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re
