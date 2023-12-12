/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:34:29 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 23:41:39 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = ft_strlen(dest);
	i = dst_len;
	j = 0;
	if (size <= dst_len)
		return (size + ft_strlen(src));
	while (src[j] && i < size - 1)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dst_len + ft_strlen(src));
}

/*
int main(int argc, char **argv)
{
 
if (argc == 2)
{
printf("ENTREE  \n");
size_t taille = (size_t)(ft_atoi(argv[1]));
char s1[] = "123456789";
char s2[] = "abcde";
 
printf("Chaine S1 :");
printf("%s", s1);
printf('\n');
printf("Chaine S2 :");
printf("%s", s2);
printf('\n');
printf("Taille de S1 :");
printf("%ld", strlen(s1));
printf('\n');
printf("Taille de S2 :");
printf("%ld", strlen(s2));
printf('\n');
printf("Taille de SIZE :");
printf("%ld", taille);
printf('\n');
printf("STRLCAT renvoie :");
 
printf(strlcat(s1, s2, taille));
 
printf('\n');
printf("Chaine S1 apres STRLCAT:");
printf(s1);
printf('\n');
printf("Taille de S1 apres STRLCAT :");
printf("%ld", strlen(s1));
printf('\n');
}
return 0;
}*/