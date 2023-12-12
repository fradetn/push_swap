/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:31:15 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 19:35:51 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
#include <strings.h>

int main(void)
{
	char str1[5] = "salu";
	char str2[5] = "salu";
	printf("%s\n",str1);
	printf("%s\n",str2);
	ft_bzero(str1, 3);
	bzero(str2, 3);
	printf("%s\n",str1);
	printf("%s\n",str2);
}*/