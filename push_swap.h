/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:21:47 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 20:36:13 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				position;
	struct s_list	*next;
}		t_list;

t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list **new);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
int			ft_atoi(const char *str);
void		help_atoi(int res, int nb, int sign);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
int			check_doubles(char **arg);
int			check_empty(int ac, char **av);
char		**store_data(int ac, char **av);
void		free_data(char **arg);
int			check_valid_input(char **arg);
int			check_sorted_str(char **str);
t_list		*creat_stack(char **av);
int			check_spaces(char **arg);
void		sa(t_list **stack_a, int flag);
void		sb(t_list **stack_b, int flag);
void		ra(t_list **stack_a, int flag);
void		rb(t_list **stack_b, int flag);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_b, t_list **stack_a);
void		rra(t_list **stack_a, int flag);
void		rrb(t_list **stack_b, int flag);
void		ss(t_list **stack_a, t_list **stack_b, int flag);
void		rr(t_list **stack_a, t_list **stack_b, int flag);
void		rrr(t_list **stack_a, t_list **stack_b, int flag);
void		first_algo(t_list **stack);
int			check_sorted(t_list *stack);
void		seconde_algo(t_list **stack_a, t_list **stack_b);
void		help_func(t_list **stack_a, t_list **stack_b, t_list *tmp);
void		help_func1(t_list **stack_a, t_list *tmp);
void		push_min(t_list **stack_a, t_list **stack_b);
int			get_index(t_list *stack_a, int elm);
int			get_min(t_list *stack_a);
void		third_algo(t_list **stack_a, t_list **stack_b);
void		indexing(t_list **stack_a);
void		indexer(t_list **stack_a, int i, int min);
int			get_next(t_list *stack_a, int elem);
int			get_max(t_list *stack_a);
void		check_numbs(t_list **stack_a, t_list **stack_b);
void		push_rotate(t_list **stack_a, t_list **stack_b,
				int chunk, int half);
void		helper(t_list **stack_a, t_list **stack_b, int chunk);
void		helper2(t_list **stack_a, t_list **stack_b, int max);
void		check_numbs_seconde(t_list **stack_a, t_list **stack_b);
int			check_sorted_str(char **str);
void		free_stack(t_list **stack_a, t_list **stack_b);
void		check_size(t_list **stack_a, t_list **stack_b);
int			ft_perror(int ac, char **av);

#endif