# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodde <jodde@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 14:58:54 by jodde             #+#    #+#              #
#    Updated: 2026/01/26 15:16:42 by jodde            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET := megaphone
SRCS := megaphone.cpp
OBJS := megaphone.o
CC := g++
CFLAGS := -Wall -Werror -Wextra -std=c++98

all : $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	@rm -f $(OBJS)
fclean : clean
	@rm -f $(TARGET)
re : fclean all
.PHONY : clean fclean re
	

