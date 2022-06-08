/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:59:29 by iayni             #+#    #+#             */
/*   Updated: 2022/04/28 01:28:23 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*handler(int n)
{
	char	*handit;

	if (n)
		handit = ft_strdup("-2147483648");
	else
		handit = ft_strdup("0");
	return (handit);
}

static	int	cheackp(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static	int	len(int n, int count)
{
	if (cheackp(n))
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		a;
	int		count;
	char	*pt;

	count = 0;
	if (n == -2147483648 || n == 0)
		return (pt = handler(n));
	count = len(n, count);
	pt = (char *) malloc(count + 1);
	if (!pt)
		return (NULL);
	if (cheackp(n))
	{
		n = n * (-1);
		pt[0] = '-';
	}
	pt[count] = '\0';
	while (n)
	{
		a = n % 10;
		pt[--count] = a + 48;
		n = n / 10;
	}
	return (pt);
}
