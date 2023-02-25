/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:21:04 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 20:23:37 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*creat_stack(char **av)
{
	t_list	*top;
	t_list	*tmp;
	int		i;

	top = NULL;
	tmp = NULL;
	i = 1;
	top = ft_lstnew(ft_atoi(av[0]));
	while (av[i])
	{
		free(av[0]);
		av[0] = NULL;
		tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&top, tmp);
		tmp = NULL;
		free(av[i]);
		av[i] = NULL;
		i++;
	}
	free(av);
	av = NULL;
	return (top);
}

int	check_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	free_data(char **arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return ;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	*arg = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b, int flag)
{
	ra(stack_a, flag);
	rb(stack_b, flag);
	ft_putstr_fd("rr\n", 1);
}
