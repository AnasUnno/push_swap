/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:42:56 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/26 23:30:07 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

# define BUFFER_SIZE 50

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_b, t_list **stack_a);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list **new);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
int			ft_atoi(const char *str);
void		help_atoi(long res);
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
int			check_sorted(t_list *stack);
t_list		*creat_stack(char **av);
int			check_spaces(char **arg);
int			check_moves(char *str, t_list **stack_a, t_list **stack_b);
void		caller(t_list **stack_a, t_list **stack_b);
void		free_stack(t_list **stack_a, t_list **stack_b);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
int			ft_perror(int ac, char **av);

#endif