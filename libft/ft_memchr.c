/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:08:12 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 22:56:04 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *) s;
	uc = (unsigned char) c;
	if (uc == '\0' && n > ft_strlen(s))
		return ((char *)(s + ft_strlen(s)));
	while (n > 0)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("ft_strchr : %s\n", (char *)ft_memchr(argv[1], 99, 5));
	printf("ft_strchr : %s\n", (char *)memchr(argv[1], 99, 5));
}*/