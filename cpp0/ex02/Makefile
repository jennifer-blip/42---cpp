# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 10:32:21 by jodde             #+#    #+#              #
#    Updated: 2026/02/13 11:16:56 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====Project=====
TARGET := accounts

#=====Compiler====
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Winit-self -Wuninitialized -Werror -O0 -g

#=====Includes and dependancies=====
INCL := -I.
DEPFLAGS := -MMD -MD

#=====Directories====

OBJ_DIR := obj

#=====Sources======
SRCS := Account.cpp tests.cpp
OBJS := $(OBJ_DIR)/Account.o $(OBJ_DIR)/tests.o
DEPS := $(OBJS:.o=.d)

#=====Rules======
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ_DIR)
fclean : clean
	rm -f $(TARGET)
re : fclean all

#=====auto dependancies====
-include $(DEPS)
.PHONY : clean fclean re
