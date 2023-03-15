/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:22:38 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 20:24:14 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	if (ft_lstsize(*stack_b) == 2)
	{
		tmp->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = tmp;
	}
	else
	{
		tmp2 = tmp->next;
		tmp->next = *stack_b;
		(*stack_b)->next = tmp2;
		*stack_b = tmp;
	}
	if (flag == 0)
		ft_putstr_fd("sb\n", 1);
}

void	rb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	t_list	*top;

	if (!((*stack_b)->next))
		return ;
	top = *stack_b;
	tmp = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = top;
	top->next = NULL;
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	int		i;

	i = ft_lstsize(*stack_b);
	tmp = ft_lstlast(*stack_b);
	tmp->next = *stack_b;
	*stack_b = tmp;
	while (i-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (flag == 2)
		ft_putstr_fd("rrb\n", 1);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	ft_lstadd_front(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	rra(stack_a, flag);
	rrb(stack_b, flag);
	ft_putstr_fd("rrr\n", 1);
}
