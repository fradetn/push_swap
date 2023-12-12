/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_no_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 05:55:43 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/07 23:19:07 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_no_nl(char *str)
{
	char	*dup;
	int		nl;
	int		len;
	int		i;

	len = ft_strlen(str);
	nl = 1;
	if (str[len - 1] == '\n')
		nl = 0;
	dup = malloc(sizeof(char) * (len + nl));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}