/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:08:33 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 21:05:07 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0' && *s != uc)
	{
		s++;
	}
	if (*s == uc)
		return ((char *) s);
	return (NULL);
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main()
{
	char		*str;
	char		str2[] = "bonjour";
			//printf("%s", str2);

		if (!(str = strchr(str2, 's')))
		{
			printf("%s", str);
			ft_print_result("NULL");
		}
		else
			ft_print_result(str);
	return (0);
}*/