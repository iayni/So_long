/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:15:40 by iayni             #+#    #+#             */
/*   Updated: 2022/05/22 22:46:48 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	char	*buffd;
	char	*buffs;

	d = (char *)dst ;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		buffs = s + (len - 1);
		buffd = d + (len - 1);
		while (len--)
			*buffd-- = *buffs--;
	}
	return (dst);
}
