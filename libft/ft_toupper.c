/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:54:38 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/04 18:06:29 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	else
		return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	i;

	i = -127;
	while (i < 255)
	{
		if (ft_toupper(i) != toupper(i))
		{
			printf("erreur pour i = %d", i);
			printf("ft_toupper = %d", ft_toupper(i));
			printf("toupper = %d", toupper(i));
			i = 300;
		}
		i++;
	}
	if (i < 300)
	{
		printf("tout est bon !");
	}
}*/