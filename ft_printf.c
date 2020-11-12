/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:44:08 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/12 17:48:35 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	for_parse_width(t_str *str, va_list ap, int start_flag)
{
	int trash;

	if (!str->width || !start_flag)
	{
		str->width = va_arg(ap, int);
		if (str->width < 0)
		{
			str->width = -str->width;
			str->flag_minus = 1;
		}
		return (1);
	}
	else
	{
		trash = va_arg(ap, int);
		return (start_flag);
	}
}

const char	*parse_flag(const char *s, t_str *str)
{
	while (ft_strchr("#0-+ ", *s) && *s)
	{
		if (*s == '#')
			str->flag_hash = 1;
		else if (*s == '0')
			str->flag_zero = 1;
		else if (*s == '-')
			str->flag_minus = 1;
		else if (*s == ' ')
			str->flag_space = 1;
		else if (*s == '+')
			str->flag_plus = 1;
		++s;
	}
	return (s);
}

const char	*parse_width(const char *s, t_str *str, va_list ap)
{
	int	start_flag;

	start_flag = 0;
	if (*s == '*')
	{
		start_flag = for_parse_width(str, ap, start_flag);
		++s;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (!(str->width) || start_flag)
			str->width = ft_atoi(s);
		++s;
	}
	if (*s == '*')
	{
		start_flag = for_parse_width(str, ap, start_flag);
		++s;
	}
	printf("HELLO: %s\n",s);
	return (s);
}

int	whole_parser(const char *s, t_str *str, va_list ap)
{
	const char *start;

	start = s;
	s = parse_flag(s, str);
	printf("WHOLE_PARSE1: %s\n", s);
	//s = parse_accuracy(s, str, ap);
	s = parse_width(s, str, ap);
	printf("WHOLE_PARSE2: %s\n", s);
	// s = parse_p(s, str, ap);
	// s += parse_mod(s, str);
	// s = parse_c(s, str);
	return (s - start);
}

void	if_zero(t_str *block, int *count)
{
	ft_bzero(block, sizeof(*block));
	*count = 0;
}


int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_str	str;
	int		count;
	int		temp;

	if_zero(&str, &count);
	va_start(ap, format);
	format += whole_parser(format + 1, &str, ap) + 1;
	printf("%s\n", format);
	return 1;
}

int main() {
	ft_printf("*05d", 123);
	return 0;
}

