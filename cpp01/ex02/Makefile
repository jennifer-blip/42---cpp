# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 15:48:09 by jodde             #+#    #+#              #
#    Updated: 2026/02/22 17:15:45 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#========Project==================
NAME := main

#=======Compiler and flags========
CPP := c++ 
CFLAGS := -std=c++98 -Wall -Wextra -Wconversion -Wshadow -Wpedantic -Winit-self -Wuninitialized -Werror -O0 -g

#======Directories===============
#======Includes and dependancies=
#======Sources===================

SRCS := main.cpp
OBJS := main.o

#======Rules=====================

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) $< -o $@

$(OBJS) : $(SRCS)
	$(CPP) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

#======auto-dependencies========
.PHONY : all re fclean clean

