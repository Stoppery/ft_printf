/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:44:08 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/13 17:54:10 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int			whole_parser(const char *s, t_str *str, va_list ap)
{
	const char *start;

	start = s;
	s = parse_flag(s, str);
	s = parse_width(s, str, ap);
	s = parse_accuracy(s, str, ap);
	s = parse_specificator(s, str);
	printf("flag_hash: %d \n flag_zero: %d \n flag_minus: %d \n flag_space: %d \n flag_plus: %d \n flag_accuracy: %d \n accuracy: %d \n width: %d \n specif: %d\n", str->flag_hash,str->flag_zero,str->flag_minus, str->flag_space, str->flag_plus, str->flag_accuracy, str->accuracy, str->width, str->specif);
	return (s - start);
}

void		if_zero(t_str *block, int *count)
{
	ft_bzero(block, sizeof(*block));
	*count = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_str	str;
	int		count;

	if_zero(&str, &count);
	va_start(ap, format);
	format += whole_parser(format + 1, &str, ap) + 1;
	return (1);
}
