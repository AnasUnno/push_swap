# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:41:40 by araji-af          #+#    #+#              #
#    Updated: 2023/02/25 20:27:44 by araji-af         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_split.c ft_substr.c parsing.c pass_to_stack.c utils2.c utils.c A_actions.c B_actions.c main.c\
	algo1.c utils3.c algo2.c algo3.c algo4.c check.c
NAME = push_swap

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all :  $(NAME)

$(NAME) : $(SRCS) $(OBJ) push_swap.h
	cc $(FLAGS) $(SRCS) -o $(NAME)

%.o: %.c
	cc -c $< -o $@
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : clean all