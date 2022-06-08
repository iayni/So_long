/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:20:45 by iayni             #+#    #+#             */
/*   Updated: 2022/04/28 01:26:40 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				d;
	char			*pt;

	d = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[d])
		d++;
	pt = (char *)malloc((d + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	while (s[i] != '\0')
	{
		pt[i] = f(i, s[i]);
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
