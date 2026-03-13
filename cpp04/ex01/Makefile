# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 10:12:19 by jodde             #+#    #+#              #
#    Updated: 2026/03/13 09:18:01 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#======================Project====================
NAME := brain
#======================Compiler===================
C+ := c++
CFLAGS := -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow -Wno-shadow -Winit-self -Wconversion -std=c++98 -O0 -g
#======================Dependencies================
INCL := -I./includes
DEPFLAGS := -MMD -MP
#======================Directories================
SRC_DIR := srcs
OBJ_DIR := objs
#======================Sources====================
SRCS := $(SRC_DIR)/Animal.cpp $(SRC_DIR)/Cat.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/display.cpp $(SRC_DIR)/Brain.cpp 
OBJS := $(OBJ_DIR)/Animal.o $(OBJ_DIR)/Cat.o $(OBJ_DIR)/Dog.o $(OBJ_DIR)/main.o $(OBJ_DIR)/display.o $(OBJ_DIR)/Brain.o 
DEPS := $(OBJ_DIR:.o=.d)
#======================Rules======================
all : $(NAME)
$(NAME) : $(OBJS)
	$(C+) $(CFLAGS) $^ -o $@
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(C+) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $^ -o $@
clean :
	@rm -rf $(OBJ_DIR)
fclean : clean
	@rm -rf $(NAME)
re : fclean all
#=====================Auto dependencies===========
- include : $(DEPS)
.PHONY : all re fclean clean