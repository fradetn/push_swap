/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:08:06 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 21:06:55 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	uc;

	uc = (unsigned char)c;
	ptr = NULL;
	if (*s == '\0' && uc != '\0')
		return (NULL);
	else if (uc == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == uc)
			ptr = s;
		s++;
	}
	if (ptr != NULL)
		return ((char *) ptr);
	return (NULL);
}

/*
int main(void)
{
        char s[] = "tripouille";
         printf("%s",ft_strrchr(s, 't' + 256));
        write(1, "\n", 1);
        return (0);
}
*/