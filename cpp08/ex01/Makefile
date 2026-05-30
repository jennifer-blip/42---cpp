# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 19:43:19 by jodde             #+#    #+#              #
#    Updated: 2026/05/30 12:59:02 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#======================Project====================
NAME := span
#======================Compiler===================
C+ := c++
CFLAGS := -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow -Winit-self -std=c++98 -O0 -g
#======================Dependencies================
INCL := -I./
DEPFLAGS := -MMD -MP
#======================Directories================
OBJ_DIR := objs
#======================Sources====================
SRCS := ./Span.cpp ./main.cpp
OBJS := $(OBJ_DIR)/Span.o $(OBJ_DIR)/main.o
DEPS := $(OBJ_DIR:.o=.d)
#======================Rules======================
all : $(NAME)
$(NAME) : $(OBJS)
	$(C+) $(CFLAGS) $^ -o $@
$(OBJ_DIR)/%.o : ./%.cpp
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
