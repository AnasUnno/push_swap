/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:15:41 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/26 23:25:02 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	while (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	stack_b = NULL;
}

int	ft_perror(int ac, char **av)
{
	if (!check_empty(ac, av) || !check_spaces(av + 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (char)c)
	{	
		if (!*s)
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}
