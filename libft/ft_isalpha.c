/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:37:55 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/03 18:37:56 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1024);
	}
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main (int argc, char **argv)
{
    (void) argc;
    printf("%d\n", ft_isalpha(argv[1][0]));
    printf("%d\n", isalpha(argv[1][0]));
}*/