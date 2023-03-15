/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:20:21 by araji-af          #+#    #+#             */
/*   Updated: 2023/02/10 13:21:30 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char const		*subs;	
	char			*a;

	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		subs = malloc((sizeof (char) * (ft_strlen(s) - start + 1)));
	else
		subs = malloc((sizeof (char) * (len + 2)));
	if (!subs)
		return (NULL);
	i = 0;
	a = (char *)subs;
	while (len-- && s[start])
		a[i++] = s[start++];
	a[i] = '\0';
	return ((char *)subs);
}
