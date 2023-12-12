/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:45:42 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/05 05:55:50 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_ptr(unsigned long ptr)
{
	if (ptr)
	{
		return (ft_putstr_printf("0x", 1) + 
			ft_putulnbr_base(ptr, "0123456789abcdef"));
	}
	return (ft_putstr_printf("(nil)", 1));
}

static int	ft_is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'p' || c == 'X')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x')
		return (1);
	return (0);
}

static int	ft_nb_args(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i + 1])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i++;
			else if (ft_is_valid(str[i + 1]))
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

static int	ft_call_arg(va_list args, const char conv)
{
	if (conv == 'd' || conv == 'i')
		return (ft_putnbr_printf(va_arg(args, int), 1));
	else if (conv == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (conv == 'c')
		return (ft_putchar_printf(va_arg(args, int), 1));
	else if (conv == 's')
		return (ft_putstr_printf(va_arg(args, char *), 1));
	else if (conv == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (conv == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (conv == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			count += ft_putchar_printf('%', 1);
			i++;
		}
		else if (format[i] == '%' && ft_is_valid(format[i + 1]))
		{
			count += ft_call_arg(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			count += ft_putchar_printf(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

/*
int ft_check_result(int nb1, int nb2)
{
	if (nb1 == nb2)
	{
		printf("\nOK\n");
		return (1);
	}
	printf("\nPAS OK\n");
	printf("nb1 = %d\nnb2 = %d\n", nb1, nb2);
	return (0);
}


int	main()
{
	int n;
	int	nb;

	printf("\npointeur\n");
	n = printf("%p \n", "255");
	nb = ft_printf("%p \n", "255");
	ft_check_result(n, nb);

	n = printf("%p %p \n", 0, 0);
	nb = ft_printf("%p %p \n", 0, 0);
	ft_check_result(n, nb);

	n = printf("%p \n", "255");
	nb = ft_printf("%p \n", "255");
	ft_check_result(n, nb);
	

	printf("\nstring\n");
	n = printf("%s \n", "255");
	nb = ft_printf("%s \n", "255");
	ft_check_result(n, nb);

	n = printf("%s \n", NULL);
	nb = ft_printf("%s \n", NULL);
	ft_check_result(n, nb);
	

	printf("\nint\n");
	n = printf("%d \n", -2147483647);
	nb = ft_printf("%d \n", -2147483647);
	ft_check_result(n, nb);
	

	printf("\nunsigned int\n");
	n = printf("%u \n", 0);
	nb = ft_printf("%u \n", 0);
	ft_check_result(n, nb);
	

	printf("\nchar\n");
	n = printf("%c \n", 'c');
	nb = ft_printf("%c \n", 'c');
	ft_check_result(n, nb);
	

	printf("\nhexa min\n");
	n = printf("%x \n", 429496729);
	nb = ft_printf("%x \n", 429496729);
	ft_check_result(n, nb);
	

	printf("\nhexa maj\n");
	n = printf("%X \n", 255);
	nb = ft_printf("%X \n", 255);
	ft_check_result(n, nb);
	

	printf("\ntout\n");
	n = printf("%c%d%s%i%x%%%%%%%%t", '&', 1, "oui", 1, 1245);
	printf("\n");
	nb = ft_printf("%c%d%s%i%x%%%%%%%%t", '&', 1, "oui", 1, 1245);
	ft_check_result(n, nb);
}*/