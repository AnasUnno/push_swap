/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:15:41 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 19:24:31 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_str(char **str)
{
	int	i;
	int	j;

	if (!str || !(*str))
		return (0);
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) < ft_atoi(str[j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	free_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	stack_a = NULL;
	stack_b = NULL;
}

void	check_size(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 3)
		first_algo(stack_a);
	else if (size <= 5)
		seconde_algo(stack_a, stack_b);
	else
		check_numbs_seconde(stack_a, stack_b);
}

int	ft_perror(int ac, char **av)
{
	if (!check_empty(ac, av) || !check_spaces(av + 1))
	{
		ft_putstr_fd("Error", 2);
		return (0);
	}
	else if (!check_valid_input(av + 1))
	{
		ft_putstr_fd("Error", 2);
		return (0);
	}
	return (1);
}
