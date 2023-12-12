/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:38:26 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/04 12:54:27 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
	{
		return (16384);
	}
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main ()
{
    int i;

    i = 0;
    while (i < 255)
    {
        if (ft_isprint(i) != isprint(i))
        {
            printf("test failed for i : %d\n", i);
            printf("ft_isprint : %d\n", ft_isprint(i));
            printf("isprint : %d\n", isprint(i));
            i = 600;
        }
        i++;
    }
    printf("Everything's fine\n");
}*/