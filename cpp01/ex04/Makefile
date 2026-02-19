# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 09:43:25 by jodde             #+#    #+#              #
#    Updated: 2026/02/19 13:43:13 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========Project==========
TARGET := replace

#==========Compiler=========
CC := g++
CFLAGS := -std=c++98 -Wextra -Werror -Wall -Wconversion -Wpedantic -Winit-self -Wshadow -Wuninitialized -O0 -g

#==========Includes and deps==
INCL := -I.
DEPFLAGS := -MMD -MD

#==========Directories=======
OBJ_DIR := ./objs

#==========Sources===========
SRCS := main.cpp replace.cpp
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/replace.o
DEPS := $(OBJS:.o=.d)

#==========Rules=============

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(TARGET)
	@rm *.replace

re : fclean all

#============Auto dependecies=====
-include $(DEPS)
.PHONY : all re fclean clean