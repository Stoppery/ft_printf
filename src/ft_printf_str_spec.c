/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:42 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/14 18:17:13 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	padding(int length, char c)
{
	while (length)
	{
		write(1, &c, 1);
		--length;
	}
}

int		spec_c(t_str *str, va_list parametr)
{
	char	c;

	c = va_arg(parametr, int);
	if (str->width && !str->flag_minus && !str->flag_zero)
		padding(str->width - 1, ' ');
	if (str->width && str->flag_zero)
		padding(str->width - 1, '0');
	write(1, &c, 1);
	if (str->width && str->flag_minus)
		padding(str->width - 1, ' ');
	if (str->width)
		return (str->width);
	else
		return (1);
}

int		spec_s(t_str *str, va_list parametr)
{
	char	*s;
	int		len;

	s = va_arg(parametr, char*);
	if (s)
		len = ft_strlen(s);
	else
		len = 6;
	if (str->flag_accuracy && str->accuracy < len)
		len = str->accuracy;
	if (str->width && !str->flag_minus && !str->flag_zero && str->width > len)
		padding(str->width - len, ' ');
	if (str->width && str->flag_zero && str->width > len)
		padding(str->width - len, '0');
	if (s)
		write(1, s, len);
	else
		write(1, "(null)", len);
	if (str->width && str->flag_minus && str->width > len)
		padding(str->width - len, ' ');
	if (str->width > len)
		return (str->width);
	else
		return (len);
}

int		spec_percent(t_str *str)
{
	if (str->width && !str->flag_minus && !str->flag_zero)
		padding(str->width - 1, ' ');
	if (str->width && str->flag_zero)
		padding(str->width - 1, '0');
	write(1, "%", 1);
	if (str->width && str->flag_minus)
		padding(str->width - 1, ' ');
	if (str->width)
		return (str->width);
	else
		return (1);
}
