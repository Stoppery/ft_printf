/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_for_numbers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:08:52 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/15 20:13:47 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		number_rank(unsigned long n, int base)
{
	int	rank;

	rank = 0;
	if (!n)
		return (1);
	while (n)
	{
		rank++;
		n /= base;
	}
	return (rank);
}

char	for_sign(t_str *str, long n)
{
	char	sign;

	if (str->flag_space)
		sign = ' ';
	else
		sign = '+';
	if (n < 0)
	{
		sign = '-';
		str->negative = 1;
	}
	return (sign);
}

int		str_len(t_str *str, int length, char *extra_symbols)
{
	int	s_length;

	if (str->flag_accuracy && str->accuracy > length)
		s_length = str->accuracy;
	else
		s_length = length;
	if (str->specif == 3 && (str->flag_space || str->flag_plus
		|| str->negative))
		s_length += 1;
	if (str->extra_symbol)
		s_length += ft_strlen(extra_symbols);
	return (s_length);
}

void	str_padding(t_str *str, int length, int str_length, int seg)
{
	if (!str->flag_zero && !str->flag_minus && str->width > str_length &&
		seg == 1)
		padding(str->width - str_length, ' ');
	else if (!str->flag_zero && str->flag_minus && str->width > str_length &&
		seg == 2)
		padding(str->width - str_length, ' ');
	else if (seg == 0)
	{
		if (str->flag_accuracy)
		{
			if (str->accuracy > length)
				padding(str->accuracy - length, '0');
			else
				return ;
		}
		else if (str->flag_zero && str->width)
		{
			if (str->width > str_length)
				padding(str->width - str_length, '0');
			else
				return ;
		}
	}
}

char	*ft_itoa_pux(unsigned long long int p, int base, char c)
{
	char					*s;
	int						i;
	unsigned long long int	n;
	int						k;

	n = (unsigned long long int)p;
	i = number_rank(n, base);
	k = i;
	if (!(s = (char*)malloc(i + 1)))
		return (NULL);
	if (!n)
		s[0] = '0';
	while (n)
	{
		if (n % base > 9)
			s[--i] = n % base - 10 + c;
		else
			s[--i] = n % base + '0';
		n /= base;
	}
	s[k] = '\0';
	return (s);
}
