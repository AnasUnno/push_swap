/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_them_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:01:32 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/26 22:09:27 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_moves(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		return (sa(stack_a), 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		return (sb(stack_a), 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		return (ss(stack_a, stack_b), 1);
	else if (!ft_strncmp(str, "ra\n", 3))
		return (ra(stack_a), 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		return (rb(stack_b), 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		return (rr(stack_a, stack_b), 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		return (rra(stack_a), 1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		return (rrb(stack_b), 1);
	else if (!ft_strncmp(str, "rrr\n", 4))
		return (rrr(stack_a, stack_b), 1);
	else if (!ft_strncmp(str, "pa\n", 3))
		return (pa(stack_a, stack_b), 1);
	else if (!ft_strncmp(str, "pb\n", 3))
		return (pb(stack_b, stack_a), 1);
	else
		return (0);
}

void	caller(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!check_moves(str, stack_a, stack_b))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(str);
		str = get_next_line(0);
	}
	if (check_sorted(*stack_a) && !*stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
}
