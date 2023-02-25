/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:53 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/25 20:36:02 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	help_atoi(int res, int nb, int sign)
{
	if (sign == -1)
			nb = -nb;
	if (res > (INT_MAX / 10) || (res == (INT_MAX / 10) && nb > 7))
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
	if (res < (INT_MIN / 10) || (res == (INT_MIN / 10) && nb < -8))
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
}
