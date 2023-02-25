/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:10:03 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 20:28:38 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	int	min;

	min = stack_a->content;
	while (stack_a)
	{
		if (stack_a->content < min)
			min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (min);
}

int	get_index(t_list *stack_a, int elm)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content == elm)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	push_min(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		indx;
	int		mid;

	min = get_min(*stack_a);
	indx = get_index(*stack_a, min);
	mid = ft_lstsize(*stack_a) / 2;
	if (indx <= mid)
	{
		while ((*stack_a)->content != min)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->content != min)
			rra(stack_a, 2);
	}
	pb(stack_b, stack_a);
}

void	seconde_algo(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = ft_lstsize(*stack_a);
	while (i-- > 3)
		push_min(stack_a, stack_b);
	if (!check_sorted(*stack_a))
		first_algo(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
