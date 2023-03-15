/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:46:13 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/18 21:36:13 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algo(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = (*stack)->next;
	tmp2 = ft_lstlast(*stack);
	if ((*stack)->content > tmp1->content && tmp1->content < tmp2->content
		&& tmp2->content > (*stack)->content)
		sa(stack, 0);
	else if ((*stack)->content > tmp1->content && tmp1->content > tmp2->content
		&& tmp2->content < (*stack)->content)
	{
		ra(stack, 1);
		sa(stack, 0);
	}
	else if ((*stack)->content < tmp1->content && tmp1->content > tmp2->content
		&& tmp2->content > (*stack)->content)
	{
		sa(stack, 0);
		ra(stack, 1);
	}
	else if ((*stack)->content < tmp1->content && tmp1->content > tmp2->content
		&& tmp2->content < (*stack)->content)
		rra(stack, 2);
	else
		ra(stack, 1);
}

int	get_max(t_list *stack_a)
{
	int	max;

	max = stack_a->content;
	while (stack_a)
	{
		if (stack_a->content > max)
			max = stack_a->content;
		stack_a = stack_a->next;
	}
	return (max);
}

int	get_next(t_list *stack_a, int min)
{
	int	next;

	next = get_max(stack_a);
	while (stack_a)
	{
		if (stack_a->content > min && stack_a->content < next)
			next = stack_a->content;
		stack_a = stack_a->next;
	}
	return (next);
}

void	indexer(t_list **stack_a, int i, int min)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->content != min)
		tmp = tmp->next;
	tmp->index = i;
}

void	indexing(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		next;

	i = 0;
	tmp = *stack_a;
	min = get_min(*stack_a);
	indexer(stack_a, i, min);
	while (tmp)
	{
		next = get_next(*stack_a, min);
		if (min == next)
		{
			indexer(stack_a, i, next);
			return ;
		}
		indexer(stack_a, ++i, next);
		min = next;
		tmp = tmp->next;
	}
}
