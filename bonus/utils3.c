/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:53 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/26 20:55:39 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	help_atoi(long res)
{
	if (res > (INT_MAX) || (res < INT_MIN))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
