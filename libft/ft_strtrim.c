/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:29:19 by iayni             #+#    #+#             */
/*   Updated: 2022/05/22 22:46:52 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	find(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == *s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	int				j;
	unsigned int	len;
	char			*pt;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && find(&s1[i], set))
		i++;
	while (s1[j] && find(&s1[j], set))
		j--;
	len = (j - i) + 1;
	pt = ft_substr(s1, i, len);
	return (pt);
}
