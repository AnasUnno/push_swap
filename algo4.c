/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:24:35 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 20:28:26 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_prev_max(t_list *stack_a, int max)
{
	int	next;

	next = get_min(stack_a);
	while (stack_a)
	{
		if (stack_a->content < max && stack_a->content > next)
			next = stack_a->content;
		stack_a = stack_a->next;
	}
	return (next);
}

void	helper_2(t_list **stack_a, t_list **stack_b, int max)
{
	int	size;
	int	index;

	index = get_index(*stack_b, max);
	size = ft_lstsize(*stack_b);
	if (index <= size / 2)
	{
		while ((*stack_b)->content != max)
			rb(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->content != max)
			rrb(stack_b, 2);
	}
	pa(stack_a, stack_b);
}

void	check_numbs_seconde(t_list **stack_a, t_list **stack_b)
{
	int		index_prev;
	int		index_max;
	int		max;
	int		prev_max;
	int		size;

	check_numbs(stack_a, stack_b);
	while (*stack_b)
	{
		size = ft_lstsize(*stack_b) / 2;
		max = get_max(*stack_b);
		prev_max = get_prev_max(*stack_b, max);
		index_max = get_index(*stack_b, max);
		index_prev = get_index(*stack_b, prev_max);
		if ((index_max <= size && index_prev <= size && index_max > index_prev)
			|| (index_max > size && index_prev > size
				&& index_max < index_prev))
		{
			helper_2(stack_a, stack_b, prev_max);
			helper_2(stack_a, stack_b, max);
			sa(stack_a, 0);
		}
		else
			helper_2(stack_a, stack_b, max);
	}
}
