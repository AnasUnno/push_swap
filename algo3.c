/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:00:41 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/27 14:23:27 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_numbs(t_list **stack_a, t_list **stack_b)
{
	int		count;
	int		chunk;
	int		const_chunk;
	int		i;

	indexing(stack_a);
	if (ft_lstsize(*stack_a) >= 500)
		i = 10;
	else
		i = 5;
	chunk = (ft_lstsize(*stack_a) / i) - 1;
	const_chunk = (chunk / 2);
	count = 0;
	push_rotate(stack_a, stack_b, chunk, const_chunk);
}

void	push_rotate(t_list **stack_a, t_list **stack_b, int chunk, int half)
{
	int	count;
	int	i;

	count = 0;
	if (ft_lstsize(*stack_a) >= 500)
		i = 50;
	else
		i = 20;
	while (*stack_a)
	{
		if ((*stack_a)->index <= chunk)
		{
			if ((*stack_a)->index <= (chunk - half))
				pb(stack_b, stack_a);
			else
				helper(stack_a, stack_b, chunk);
			count++;
		}
		else
			ra(stack_a, 1);
		if (count == chunk)
			chunk += i;
	}
}

void	helper(t_list **stack_a, t_list **stack_b, int chunk)
{
	if ((*stack_a)->next)
	{
		if ((*stack_a)->next->index > chunk)
		{
			pb(stack_b, stack_a);
			rr(stack_a, stack_b, 3);
		}
		else
		{
			pb(stack_b, stack_a);
			rb(stack_b, 1);
		}
	}
}
