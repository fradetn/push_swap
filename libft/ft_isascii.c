/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:38:15 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/04 12:48:11 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
#include <stdio.h>
#include <ctype.h>

int main ()
{
    int i;

    i = -128;
    while (i < 255)
    {
        if (ft_isascii(i) != isascii(i))
        {
            printf("test failed for i : %d\n", i);
            printf("ft_isascii : %d\n", ft_isascii(i));
            printf("isascii : %d\n", isascii(i));
            i = 600;
        }
        i++;
    }
    printf("Everything's fine\n");
}*/