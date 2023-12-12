/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:32:03 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 19:46:54 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
	{
		*ptr++ = *(unsigned char *)src++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest1[30] = "";
	char dest2[30] = "";
	memset(dest1, 'j', 30);
	memset(dest2, 'j', 30);
    printf("dest : %s\n", dest1);
    printf("dest : %s\n", dest2);
    printf("src       : %s\n", src);
    printf("ft_memcpy : %s\n", (char *)
	ft_memcpy(dest2, "zy\0xw\0vu\0\0tsr", 14));
    printf("memcpy    : %s\n", (char *)
	memcpy(dest1, "zy\0xw\0vu\0\0tsr", 11));
    printf("dest        : %s\n", dest1);
    printf("dest memcpy : %s\n", dest2);
}*/