/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:55:12 by iayni             #+#    #+#             */
/*   Updated: 2021/12/01 23:09:00 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<string.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*src_cst;
	char		*dst_cst;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	src_cst = (char *)src;
	dst_cst = (char *)dst;
	i = 0;
	while (i < len)
	{
		dst_cst[i] = src_cst[i];
		i++;
	}
	return (dst_cst);
}
