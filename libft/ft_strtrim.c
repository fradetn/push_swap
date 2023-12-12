/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:11:17 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/09 13:27:49 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char const *set, char c)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*str;

	while (*s1 && ft_isin(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (ft_isin(set, *(s1 + len - 1)) && len > 0)
		len--;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}

/*
int	main()
{
	char *str;

	str = ft_strtrim("   xxx   xxx", " x");
	printf("%s\n", str);
	free(str);
}*/