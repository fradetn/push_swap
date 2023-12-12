/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:35:36 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/05 04:17:50 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (ft_putnbr_printf(n * -1, fd) + 1);
	}
	else if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
		return (1);
	}
	else
	{
		return (ft_putnbr_printf(n / 10, fd) + ft_putnbr_printf(n % 10, fd));
	}
}
