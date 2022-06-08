/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:14:18 by iayni             #+#    #+#             */
/*   Updated: 2022/04/26 23:19:18 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcnt(const char *str, char *c)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		if ((ft_strchr(c, str[i + 1]) && !ft_strchr(c, str[i]))
			|| (!ft_strchr(c, str[i]) && str[i + 1] == '\0'))
			cpt++;
		i++;
	}
	return (cpt);
}

static void	*freeme(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static	char	**lol(char **pt, const char *s, char *c)
{
	int		i;
	int		j;

	j = 0;
	while (*s)
	{
		i = 0;
		while (!ft_strchr(c, s[i]) && s[i] != '\0')
			i++;
		if (i > 0)
		{
			pt[j] = (char *)malloc((i + 1) * sizeof(char));
			if (!pt)
				return ((char **)freeme(pt));
			ft_memcpy(pt[j], s, i);
			pt[j][i] = '\0';
			j++;
			s = s + i;
		}
		else
			s++;
	}
	pt[j] = NULL;
	return (pt);
}

char	**ft_split(char const *s, char *c)
{
	char	**pt;

	if (!s)
		return (NULL);
	pt = (char **)malloc((wordcnt(s, c) + 1) * sizeof(char *));
	if (!pt)
		return (NULL);
	pt = lol (pt, s, c);
	return (pt);
}
