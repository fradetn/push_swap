/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:39:59 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 19:36:05 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size <= 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
    char dest1[15] = "";
    char dest2[15] = "";
    memset(dest1, 0, 15);
    memset(dest1, 'r', 6);
    memset(dest2, 0, 15);
    memset(dest2, 'r', 6);

    printf("ft_strlcpy : %ld\n", ft_strlcpy(dest1, "lorem ipsum", 3));
    printf("ft_strlcpy : %s\n", dest1);
    printf("strlcpy : %ld\n", strlcpy(dest2, "lorem ipsum", 3));
    printf("strlcpy : %s\n", dest2);
}*/