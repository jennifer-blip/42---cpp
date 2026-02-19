# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 15:48:09 by jodde             #+#    #+#              #
#    Updated: 2026/02/15 16:20:37 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#========Project==================
TARGET := main

#=======Compiler and flags========
CC := g++ 
CFLAGS := -std=c++98 -Wall -Wextra -Wconversion -Wshadow -Wpedantic -Winit-self -Wuninitialized -Werror -O0 -g

#======Directories===============
#======Includes and dependancies=
#======Sources===================

SRCS := main.cpp
OBJS := main.o

#======Rules=====================

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(TARGET)

re : fclean all

#======auto-dependencies========
.PHONY : all re fclean clean

