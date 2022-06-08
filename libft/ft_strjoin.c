/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:50:36 by iayni             #+#    #+#             */
/*   Updated: 2022/04/28 01:27:09 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*pt;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	pt = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!pt)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		pt[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		pt[i + j] = s2[j];
		j++;
	}
	pt[i + j] = '\0';
	return (pt);
}
