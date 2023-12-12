/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:37:29 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/07 03:56:20 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnum(int c)
{
	if ((c > 47 && c < 58))
	{
		return (2048);
	}
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static char	*ft_str_nospace(char *str)
{
	while (ft_isspace(*str) == 1)
	{
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	str = ft_str_nospace((char *)str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isnum(*str) != 0)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

/*
#include <limits.h>
#include <stdio.h>

int single_test(char *str)
{
	if (atoi(str) != ft_atoi(str))
	{
		printf("test incorrect\nExpected : 
		%d\nOutput : %d\n\n",atoi(str),ft_atoi(str));
		return (1);
	}
	return (0);
}

int test_atoi(void)
{
	char buffer[200];
	int res = 1;

	single_test(" \t\v\n\r\f123");
	single_test("0");
	single_test("-1000043");
	single_test(
		"+0000000000000000000000000000000000000000000000000000123");
	single_test("    123");
	single_test("--123");
	single_test("-+123");
	single_test("+-123");
	single_test("++123");
	single_test("- 123");
	single_test("+ 123");
	single_test("+\n123");
	single_test("1209");
	single_test("12/3");
	single_test("12;3");
	sprintf(buffer, "%i", INT_MAX);
	single_test(buffer);
	sprintf(buffer, "%i", INT_MIN);
	single_test(buffer);

	for (int i = 0; i <= 0xFF; i++) {
		sprintf(buffer, "%c %i", i, i + 1);
	single_test(buffer);
	}

	return res;
}

int	main()
{
	test_atoi();
}*/