/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:45:53 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/04 22:54:46 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	nb;
	int				res;

	res = 0;
	nb = nbr;
	if (nb < 16)
	{
		write(1, &base[nb], 1);
		return (1);
	}
	if (nb >= 16)
	{
		res += ft_putnbr_base(nb / 16, base);
		res += ft_putnbr_base(nb % 16, base);
	}
	return (res);
}

int	ft_putulnbr_base(unsigned long nbr, char *base)
{
	int	res;

	res = 0;
	if (nbr < 16)
	{
		write(1, &base[nbr], 1);
		return (1);
	}
	if (nbr >= 16)
	{
		res += ft_putulnbr_base(nbr / 16, base);
		res += ft_putulnbr_base(nbr % 16, base);
	}
	return (res);
}
