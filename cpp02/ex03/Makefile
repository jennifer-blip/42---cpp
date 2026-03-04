# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/27 14:27:48 by jodde             #+#    #+#              #
#    Updated: 2026/03/03 17:06:19 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================Project========
NAME := triangle
#================Compiler======
C+ := c++
CFLAGS := -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow -Winit-self -Wconversion -std=c++98 -O0 -g
#================Dependancies===
INCL := -I./Includes
DEPFLAGS := -MMD -MP
#================Directories====
SRC_DIR := ./srcs
OBJ_DIR := ./objs
#================Files==========
SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp $(SRC_DIR)/Point.cpp $(SRC_DIR)/bsp.cpp
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/Fixed.o $(OBJ_DIR)/Point.o $(OBJ_DIR)/bsp.o
DEPS := $(OBJS:.o=.d)
#================Rules==========
all : $(NAME)

$(NAME): $(OBJS)
	$(C+) $(CFLAGS) $(DEBUG) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(C+) $(CFLAGS) $(DEPFLAGS) $(INCL) -c $< -o $@
clean :
	@rm -rf $(OBJ_DIR)
fclean : clean
	@rm -rf $(NAME)
re : fclean all
#===============Auto dependencies========
-include $(DEPS)
.PHONY : re clean fclean
