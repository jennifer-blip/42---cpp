# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 10:12:19 by jodde             #+#    #+#              #
#    Updated: 2026/03/17 16:21:56 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#======================Project====================
NAME := materia
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
SRCS := $(SRC_DIR)/AMateria.cpp $(SRC_DIR)/Cure.cpp $(SRC_DIR)/Ice.cpp $(SRC_DIR)/MateriaSource.cpp $(SRC_DIR)/Character.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/display.cpp 
OBJS := $(OBJ_DIR)/AMateria.o $(OBJ_DIR)/Cure.o $(OBJ_DIR)/Ice.o $(OBJ_DIR)/MateriaSource.o $(OBJ_DIR)/Character.o $(OBJ_DIR)/main.o $(OBJ_DIR)/display.o 
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