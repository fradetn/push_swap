/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:13:11 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/10 19:12:58 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n >= 1)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	len = ft_intlen((unsigned int)n) + 1 + sign;
	str = malloc(sizeof(char) * (len));
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	if (n == 0)
		str[len - len] = '0';
	while (--len >= sign && (unsigned int)n >= 1)
	{
		str[len - 1] = ((unsigned int)n % 10) + 48;
		n = (unsigned int)n / 10;
	}
	if (sign == 1)
		str[len - 1] = '-';
	return (str);
}

/*
int	main()
{
	char  *str = ft_itoa(9);
	printf("%s\n", str);
	free(str);
}*/