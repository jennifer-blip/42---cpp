# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 10:32:21 by jodde             #+#    #+#              #
#    Updated: 2026/02/22 17:24:56 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=======Project======
NAME := Zombie

#=======Compiler and FLAGS=======
CPP:= c++
CFLAGS := -std=c++98 -Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion -Winit-self -Wuninitialized -O0 -g

#=======Include and dependencies=======
INCL:= -I.
DEPFLAGS:= -MMD -MP

#=======Directories========
OBJ_DIR := obj
SRC_DIR := srcs

#=======Files=======
SRCS:= $(SRC_DIR)/newZombie.cpp $(SRC_DIR)/Zombie.cpp $(SRC_DIR)/randomChump.cpp $(SRC_DIR)/main.cpp
OBJS:= $(OBJ_DIR)/newZombie.o $(OBJ_DIR)/Zombie.o $(OBJ_DIR)/randomChump.o $(OBJ_DIR)/main.o
DEPS:= $(OBJS:.o=.d)

#=======Rules=======

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm $(NAME)

re : fclean all

#=========dependencies=========
-include $(DEPS)
.PHONY : clean fclean re