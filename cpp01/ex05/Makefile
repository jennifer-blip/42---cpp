# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 14:14:05 by jodde             #+#    #+#              #
#    Updated: 2026/02/19 14:53:53 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#=========Project=========
TARGET := Harl

#=========Compiler========
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Werror -Wpedantic -Wshadow -Winit-self -Wconversion -Wuninitialized -O0 -g

#=========Incl. and deps===
INCL := -I.
DEPFLAGS := -MMD -MD

#=========Directories=======
OBJ_DIR := ./objs
SRC_DIR := ./srcs

#=========Sources===========
SRCS := $(SRC_DIR)/Harl.cpp $(SRC_DIR)/main.cpp
OBJS := $(OBJ_DIR)/Harl.o $(OBJ_DIR)/main.o
DEPS := $(OBJS:.o=.d)

#=========Rules=============

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCL) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(TARGET)
	
re : fclean all

#=========Auto deps==========
-include $(DEPS)
.PHONY : all re fclean clean