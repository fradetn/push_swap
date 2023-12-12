/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:38:16 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/09 18:16:54 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main()
{
	char s[] = "lorem ipsum dolor sit amet";
	char *str;

	str = ft_substr(s, 400, 20);
	printf("%s\n", str);
	free(str);

	char *bullshit;
	if (!(str = ft_substr(s, 400, 20)))
		ft_print_result("NULL");
	else
	{
		bullshit = (char *)&str[30];
		bullshit = "FULL BULLSHIT";
		if (str)
			ft_print_result(str);
		else
			ft_print_result("rip");
	}
	if (s == str)
		ft_print_result("\nA new string was not returned");
	(void)bullshit;
}*/