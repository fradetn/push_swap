/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 04:37:19 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 21:40:48 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	ncpy;

	if (*lit == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && n > 0)
	{
		k = i;
		j = 0;
		ncpy = n;
		while (big[k++] == lit[j++] && ncpy-- > 0)
		{
			if (lit[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <bsd/string.h>


int main(void)
{
        char haystack[30] = "aaabcabcd";

        printf("%s\n",strnstr(haystack, "aaabc", 4));
        //printf("%s\n",ft_strnstr(haystack, "abcd", 9)); 
        //printf("%s\n",ft_strnstr(haystack, "a", 1)); 
        write(1, "\n", 1);
        return (0);
}
*/