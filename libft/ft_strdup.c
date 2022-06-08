/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:10:38 by iayni             #+#    #+#             */
/*   Updated: 2022/04/28 01:31:26 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *sq)
{
	size_t	j;
	char	*ptr;

	j = 0;
	ptr = malloc(ft_strlen(sq) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (sq[j] != '\0')
	{
		ptr[j] = sq[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
