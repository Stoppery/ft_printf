/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:44:08 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/15 19:23:54 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			whole_parser(const char *s, t_str *str, va_list parametr)
{
	const char *start;

	start = s;
	s = parse_flag(s, str);
	s = parse_width(s, str, parametr);
	s = parse_accuracy(s, str, parametr);
	s = parse_specificator(s, str);
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

int			spec_choose(t_str *str, va_list parametr)
{
	if (str->specif == 0)
		return (spec_c(str, parametr));
	if (str->specif == 1)
		return (spec_s(str, parametr));
	if (str->specif == 2)
		return (spec_p(str, parametr));
	if (str->specif == 3)
		return (spec_d(str, parametr));
	if (str->specif == 4)
		return (spec_u(str, parametr));
	if (str->specif == 5)
		return (spec_x(str, parametr));
	if (str->specif == 6)
		return (spec_x(str, parametr));
	if (str->specif == 7)
		return (spec_percent(str));
	return (1);
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
			if (str.exist)
				count += spec_choose(&str, parametr);
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
