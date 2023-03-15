/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:38:36 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/26 23:23:03 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	if (ft_lstsize(*stack_a) == 2)
	{
		tmp->next = *stack_a;
		(*stack_a)->next = NULL;
		*stack_a = tmp;
	}
	else
	{
		tmp2 = tmp->next;
		tmp->next = *stack_a;
		(*stack_a)->next = tmp2;
		*stack_a = tmp;
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*top;

	if (!((*stack_a)->next))
		return ;
	top = *stack_a;
	tmp = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = top;
	top->next = NULL;
}

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	i = ft_lstsize(*stack_a);
	tmp = ft_lstlast(*stack_a);
	tmp->next = *stack_a;
	*stack_a = tmp;
	while (i-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b)
		return ;
	ft_lstadd_front(stack_a, stack_b);
}
