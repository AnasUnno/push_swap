/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:45:12 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/27 14:26:31 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**str;

	if (ac <= 1)
		exit(1);
	if (!ft_perror(ac, av))
		return (0);
	str = store_data(ac, av);
	if (!check_valid_input(str) || !check_doubles(str))
	{
		ft_putstr_fd("Error\n", 2);
		free_data(str);
		return (0);
	}
	if (check_sorted_str(str))
	{
		free_data(str);
		return (0);
	}
	stack_a = creat_stack(str);
	caller(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
