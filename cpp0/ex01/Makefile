# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 18:08:53 by jodde             #+#    #+#              #
#    Updated: 2026/02/21 17:28:32 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==Project==
TARGET := friends

# ==Compiler==
CC := g++ 
CFLAGS := -std=c++98 -Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion -Winit-self -Wuninitialized -O0 -g

# ==Includes and dependencies==
INCL := -I./includes #option de compilation pour dire au compilateur ou chercher le header, pour que g++ cherche les hpp dans le bon repertoire
DEPFLAGS := -MMD -MP

# ==Directories==
SRC_DIR := src
OBJ_DIR := obj

# ==Sources==
SRCS := $(SRC_DIR)/initPB.cpp $(SRC_DIR)/editPB.cpp $(SRC_DIR)/displayPB.cpp $(SRC_DIR)/contact.cpp
OBJS := $(OBJ_DIR)/initPB.o $(OBJ_DIR)/editPB.o $(OBJ_DIR)/displayPB.o $(OBJ_DIR)/contact.o
DEPS := $(OBJS:.o=.d)

# ==Rules==
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCL) $(DEPFLAGS) -c $< -o $@
clean :
	@rm -rf $(OBJ_DIR)
fclean : clean
	@rm -f $(TARGET)
re : fclean all

# ==Auto dependencies==
-include $(DEPS) #make lit les dependances, si une dependance est plus recente que la cible, il y a recompilation
.PHONY : clean fclean re


