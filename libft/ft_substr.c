/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:48:22 by iayni             #+#    #+#             */
/*   Updated: 2021/12/01 23:12:29 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static char	*handler(unsigned int len, const char *s)
{
	char			*ptr;
	int				i;
	unsigned int	slen;

	slen = ft_strlen(s);
	i = 0;
	ptr = NULL;
	if (len > slen)
		i = slen;
	else
		i = len;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*pt;

	if (!s)
		return (NULL);
	i = 0;
	pt = handler(len, s);
	if (!pt)
		return (NULL);
	while (start < ft_strlen(s) && len != 0)
	{
		pt[i] = s[start];
		i++;
		len--;
		start++;
	}
	pt[i] = '\0';
	return (pt);
}
