/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:26:29 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/04 12:48:12 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1024);
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
	{
		return (2048);
	}
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int main (int argc, char **argv)
{
    (void) argc;
    printf("%d\n", ft_isalnum(argv[1][0]));
    printf("%d\n", isalnum(argv[1][0]));
}*/