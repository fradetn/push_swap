/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 05:06:37 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/05 04:14:43 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_printf(char *s, int fd)
{
	if (!s)
		return (ft_putstr_printf("(null)", 1));
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
