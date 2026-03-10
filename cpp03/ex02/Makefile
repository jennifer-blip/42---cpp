# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 10:12:19 by jodde             #+#    #+#              #
#    Updated: 2026/03/09 11:38:40 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#======================Project====================
NAME := fragtrap
#======================Compiler===================
C+ := c++
CFLAGS := -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow -Winit-self -Wconversion -std=c++98 -O0 -g
#======================Dependencies================
INCL := -I./includes
DEPFLAGS := -MMD -MP
#======================Directories================
SRC_DIR := srcs
OBJ_DIR := objs
#======================Sources====================
SRCS := $(SRC_DIR)/ClapTrap.cpp $(SRC_DIR)/ScavTrap.cpp $(SRC_DIR)/FragTrap.cpp $(SRC_DIR)/main.cpp
OBJS := $(OBJ_DIR)/ClapTrap.o $(OBJ_DIR)/ScavTrap.o $(OBJ_DIR)/FragTrap.o $(OBJ_DIR)/main.o
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