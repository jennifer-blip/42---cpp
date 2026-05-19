# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 19:43:19 by jodde             #+#    #+#              #
#    Updated: 2026/05/19 20:19:26 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#======================Project====================
NAME := convert
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
SRCS := $(SRC_DIR)/ScalarConverter.cpp \
		$(SRC_DIR)/Scalar.cpp \
		$(SRC_DIR)/CharValue.cpp \
		$(SRC_DIR)/IntValue.cpp \
		$(SRC_DIR)/FloatValue.cpp \
		$(SRC_DIR)/DoubleValue.cpp \
		$(SRC_DIR)/parseType.cpp \
		$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/display.cpp
OBJS := $(OBJ_DIR)/ScalarConverter.o \
		$(OBJ_DIR)/Scalar.o \
		$(OBJ_DIR)/CharValue.o \
		$(OBJ_DIR)/IntValue.o \
		$(OBJ_DIR)/FloatValue.o \
		$(OBJ_DIR)/DoubleValue.o \
		$(OBJ_DIR)/parseType.o \
		$(OBJ_DIR)/main.o \
		$(OBJ_DIR)/display.o
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
