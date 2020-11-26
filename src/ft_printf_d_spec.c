/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:06:36 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/26 16:52:41 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_d(long n)
{
	char	*s;
	int		i;
	long	k;
	int		p;

	k = (n < 0) ? -n : n;
	i = number_rank(k, 10);
	p = i;
	if (!(s = (char*)malloc(i + 1)))
		return (NULL);
	if (!n)
		s[0] = '0';
	while (n)
	{
		if (n > 0)
			s[--i] = n % 10 + '0';
		else
			s[--i] = -(n % 10) + '0';
		n /= 10;
	}
	s[p] = '\0';
	return (s);
}

int		spec_d(t_str *str, va_list parametr)
{
	long		n;
	char		sign;
	char		*s;
	int			length;
	int			str_length;

	n = (long)va_arg(parametr, int);
	s = ft_itoa_d(n);
	str->flag_zero = (str->flag_accuracy) ? 0 : str->flag_zero;
	str->flag_space = (str->flag_plus) ? 0 : str->flag_space;
	sign = for_sign(str, n);
	length = str->flag_accuracy && !str->accuracy && n == 0 ? 0 : ft_strlen(s);
	str_length = str_len(str, length, NULL);
	str_padding(str, length, str_length, 1);
	if (n < 0 || str->flag_plus || str->flag_space)
		write(1, &sign, 1);
	str_padding(str, length, str_length, 0);
	write(1, s, length);
	str_padding(str, length, str_length, 2);
	free(s);
	if (str->width > str_length)
		return (str->width);
	else
		return (str_length);
}
