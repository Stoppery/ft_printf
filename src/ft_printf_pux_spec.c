/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pux_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:33:40 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/26 16:33:33 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	spec_p(t_str *str, va_list parametr)
{
	unsigned long long int	p;
	char					*s;
	int						length;
	int						str_length;

	p = va_arg(parametr, unsigned long long int);
	s = ft_itoa_pux(p, 16, 'a');
	str->extra_symbol = 1;
	if (str->flag_accuracy && !str->accuracy && !p)
		length = 0;
	else
		length = ft_strlen(s);
	str_length = str_len(str, length, "0x");
	str_padding(str, length, str_length, 1);
	write(1, "0x", 2);
	str_padding(str, length, str_length, 0);
	write(1, s, length);
	str_padding(str, length, str_length, 2);
	free(s);
	if (str->width > str_length)
		return (str->width);
	else
		return (str_length);
}

int	result_ux(t_str *str, unsigned long long n, char *s, char *extra)
{
	int	length;
	int str_length;

	str->flag_zero = (str->flag_accuracy) ? 0 : str->flag_zero;
	str->flag_space = (str->flag_plus) ? 0 : str->flag_space;
	length = str->flag_accuracy && !str->accuracy && n == 0 ? 0 : ft_strlen(s);
	str_length = str_len(str, length, extra);
	str_padding(str, length, str_length, 1);
	if (str->extra_symbol)
		write(1, extra, ft_strlen(extra));
	str_padding(str, length, str_length, 0);
	write(1, s, length);
	str_padding(str, length, str_length, 2);
	free(s);
	if (str->width > str_length)
		return (str->width);
	else
		return (str_length);
}

int	spec_u(t_str *str, va_list parametr)
{
	unsigned long long int			u;
	char							*s;

	u = va_arg(parametr, unsigned int);
	s = ft_itoa_pux(u, 10, 0);
	return (result_ux(str, u, s, NULL));
}

int	spec_x(t_str *str, va_list parametr)
{
	unsigned long long int	x;
	char					*s;
	char					*extra;
	char					eight_conversation;

	x = va_arg(parametr, unsigned int);
	if (str->specif == 6)
		eight_conversation = 'A';
	else
		eight_conversation = 'a';
	s = ft_itoa_pux(x, 16, eight_conversation);
	if (str->flag_hash && x)
	{
		if (str->specif == 6)
			extra = "0X";
		else
			extra = "0x";
		str->extra_symbol = 1;
	}
	if (str->extra_symbol)
		return (result_ux(str, x, s, extra));
	else
		return (result_ux(str, x, s, NULL));
}
