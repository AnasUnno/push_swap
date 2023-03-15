# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:41:40 by araji-af          #+#    #+#              #
#    Updated: 2023/02/27 01:44:39 by araji-af         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_split.c ft_substr.c parsing.c pass_to_stack.c utils2.c utils.c A_actions.c B_actions.c main.c\
	algo1.c utils3.c algo2.c algo3.c algo4.c check.c

SRCS_B = bonus/A_actions.c bonus/B_actions.c bonus/check_them_moves.c bonus/check.c bonus/checker.c bonus/ft_split.c bonus/ft_strncmp.c bonus/ft_substr.c \
	bonus/parsing.c bonus/pass_to_stack.c bonus/utils.c bonus/utils2.c bonus/utils3.c bonus/get_next_line.c

NAME = push_swap

NAME_B = checker

OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror

all :  $(NAME)

$(NAME) : $(SRCS) $(OBJ) push_swap.h
	cc $(FLAGS) $(SRCS) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(SRCS_B) $(OBJ_B) bonus/checker.h
	cc $(FLAGS) $(SRCS_B) -o $(NAME_B)

%.o: %.c
	cc -c $< -o $@
clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all
