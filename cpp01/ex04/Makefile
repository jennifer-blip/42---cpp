# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 09:43:25 by jodde             #+#    #+#              #
#    Updated: 2026/02/25 11:49:41 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========Project==========
NAME := replace

#==========Compiler=========
CPP := c++
CFLAGS := -std=c++98 -Wextra -Werror -Wall -Wconversion -Wpedantic -Winit-self -Wshadow -Wuninitialized -O0 -g

#==========Includes and deps==
INCL := -I./includes
DEPFLAGS := -MMD -MP

#==========Directories=======
SRC_DIR := ./srcs
OBJ_DIR := ./objs

#==========Sources===========
SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/replace.cpp $(SRC_DIR)/error.cpp
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/replace.o $(OBJ_DIR)/error.o
DEPS := $(OBJS:.o=.d)

#==========Rules=============

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)
	@rm *.replace

re : fclean all

#============Auto dependecies=====
-include $(DEPS)
.PHONY : all re fclean clean