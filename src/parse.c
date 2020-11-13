/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:53:44 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/13 17:54:13 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			for_parse_width(t_str *str, va_list ap, int start_flag)
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
	if (str->flag_minus == 1 && str->flag_zero == 1)
		str->flag_zero = 0;
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
	return (s);
}

const char	*parse_accuracy(const char *s, t_str *str, va_list ap)
{
	int	trash;

	if (*s == '.')
	{
		str->flag_accuracy = 1;
		++s;
	}
	while (*s >= '0' && *s <= '9' && str->flag_accuracy)
	{
		if (!(str->accuracy))
			str->accuracy = ft_atoi(s);
		++s;
	}
	if (*s == '*' && str->flag_accuracy)
	{
		if (!str->accuracy)
			str->accuracy = va_arg(ap, int);
		else
			trash = va_arg(ap, int);
		if (str->accuracy < 0)
			str->flag_accuracy = 0;
		++s;
	}
	return (s);
}

const char	*parse_specificator(const char *s, t_str *str)
{
	static char specificator[] = "cspduxX%";

	if (*s && (ft_strchr(specificator, *s) || *s == 'i'))
	{
		str->specif = ft_strchr(specificator, *s) - specificator;
		if (*s == 'i')
			str->specif = 3;
		++s;
	}
	return (s);
}