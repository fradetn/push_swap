/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:35:38 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/04 12:54:27 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
	{
		return (2048);
	}
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main (int argc, char **argv)
{
    (void) argc;
    printf("%d\n", ft_isdigit(argv[1][0]));
    printf("%d\n", isdigit(argv[1][0]));
}*/