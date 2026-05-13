# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 19:43:19 by jodde             #+#    #+#              #
#    Updated: 2026/05/13 12:30:14 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#======================Project====================
NAME := bureaucrat
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
SRCS := $(SRC_DIR)/Bureaucrat.cpp \
		$(SRC_DIR)/Intern.cpp \
		$(SRC_DIR)/AForm.cpp \
		$(SRC_DIR)/PresidentialPardonForm.cpp \
		$(SRC_DIR)/RobotomyRequestForm.cpp \
		$(SRC_DIR)/ShrubberyCreationForm.cpp \
		$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/display.cpp
OBJS := $(OBJ_DIR)/Bureaucrat.o \
		$(OBJ_DIR)/Intern.o \
		$(OBJ_DIR)/AForm.o \
		$(OBJ_DIR)/PresidentialPardonForm.o \
		$(OBJ_DIR)/RobotomyRequestForm.o \
		$(OBJ_DIR)/ShrubberyCreationForm.o \
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
	@rm -rf *_shrubbery
re : fclean all
#=====================Auto dependencies===========
- include : $(DEPS)
.PHONY : all re fclean clean