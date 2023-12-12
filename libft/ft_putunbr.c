/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:40:01 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/04 22:55:01 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int n)
{
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', 1);
		return (1);
	}
	else
	{
		return (ft_putunbr(n / 10) + ft_putunbr(n % 10));
	}
}
