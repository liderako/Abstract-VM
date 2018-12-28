# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2018/03/22 14:12:33 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

INCLUDE = -I ./includes/

FLAGS = -Wall -Wextra -Werror -std=c++11

SRC = 	./src/main.cpp\
		./src/ReadManager.cpp\
		./src/VirtualMachine.cpp\
		./src/ValidationManager.cpp\
		./src/Parser.cpp\
		./src/Operand.cpp\
		./src/OperandFactory.cpp\

BINS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(BINS)
	clang++ -o $(NAME) $(BINS)

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<  $(INCLUDE)

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all