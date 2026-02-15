# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 16:23:50 by jodde             #+#    #+#              #
#    Updated: 2026/02/15 17:29:53 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========Project=========
TARGET := lasergame

#==========Compiler========
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Wconversion -Wshadow -Winit-self -Wuninitialized -Wpedantic -Werror -O0 -g
#==========Includes and deps==
INCL := -I.
DEPFLAGS := -MMD -MD

#=========Directories=====
OBJ_DIR := ./obj

#=========Sources=========
SRCS := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/Weapon.o $(OBJ_DIR)/HumanA.o $(OBJ_DIR)/HumanB.o
DEPS := $(OBJS:.o=.d)

#=========Rules===========

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(TARGET)

re : fclean all

#=========Auto dependencies====
-include $(DEPS)
.PHONY : all re fclean clean