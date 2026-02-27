# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 10:54:14 by jodde             #+#    #+#              #
#    Updated: 2026/02/27 10:12:20 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===========Project=========================================================================
NAME := fixed
#===========Compiler=========================================================================
CC := c++
CFLAGS := -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow -Winit-self -Wconversion -std=c++98 -O0 -g
#===========Dependencies=========================================================================
INCL := -I.
DEPFLAGS := -MMD -MP
#===========Directories=========================================================================
SRC_DIR := ./srcs
OBJ_DIR := ./objs
#===========Files=========================================================================
SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp $(SRC_DIR)/Fixed_op.cpp
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/Fixed.o $(OBJ_DIR)/Fixed_op.o
DEPS := $(OBJS:.o=.d)
#===========Rules=========================================================================
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCL) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
fclean : clean
	@rm -f $(NAME)
re : fclean all
#=========auto dependencies========================================================================
-include $(DEPS)
.PHONY : all clean fclean re