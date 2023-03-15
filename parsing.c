/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:20:33 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/26 18:45:41 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**store_data(int ac, char **av)
{
	char	*not_splited;
	char	*tmp;
	char	**split_args;
	int		i;

	i = 1;
	not_splited = NULL;
	while (ac-- > 1)
	{
		tmp = not_splited;
		not_splited = ft_strjoin(tmp, av[i]);
		free(tmp);
		tmp = not_splited;
		not_splited = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	split_args = ft_split(not_splited, ' ');
	return (free(not_splited), split_args);
}

int	check_doubles(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_empty(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!*av[i] || !av[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_input(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		ft_atoi(arg[i]);
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
				j++;
		while (arg[i][j])
		{
			if (arg[i][j] < 48 || arg[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_spaces(char **arg)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0 ;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] == ' ')
				check = 0;
			else
			{
				check = 1;
				break ;
			}
			j++;
		}
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}
