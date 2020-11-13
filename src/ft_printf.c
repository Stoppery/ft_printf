/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:44:08 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/13 20:13:16 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int			whole_parser(const char *s, t_str *str, va_list parametr)
{
	const char *start;

	start = s;
	s = parse_flag(s, str);
	s = parse_width(s, str, parametr);
	s = parse_accuracy(s, str, parametr);
	s = parse_specificator(s, str);
	printf(" flag_hash: %d \n flag_zero: %d \n flag_minus: %d \n flag_space: %d \n flag_plus: %d \n flag_accuracy: %d \n accuracy: %d \n width: %d \n specif: %d\n exist: %d\n\n\n", str->flag_hash,str->flag_zero,str->flag_minus, str->flag_space, str->flag_plus, str->flag_accuracy, str->accuracy, str->width, str->specif, str->exist);
	return (s - start);
}

void		to_zero(t_str *str, int *count)
{
	ft_bzero(str, sizeof(*str));
	*count = 0;
}

int			no_spec(const char *s)
{
	int		length;
	char	*elem;

	elem = ft_strchr(s, '%');
	if (elem)
		length = elem - s;
	else
		length = ft_strlen(s);
	write(1, s, length);
	return (length);
}

int			ft_printf(const char *format, ...)
{
	va_list	parametr;
	t_str	str;
	int		count;
	int		tmp;

	to_zero(&str, &count);
	va_start(parametr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += whole_parser(format + 1, &str, parametr) + 1;
			// if (str.exist)
			// 	count += spec_choose(&str, parametr);
			ft_bzero(&str, sizeof(str));
		}
		else
		{
			tmp = no_spec(format);
			format += tmp;
			count += tmp;
		}
	}
	va_end(parametr);
	return (count);
}
