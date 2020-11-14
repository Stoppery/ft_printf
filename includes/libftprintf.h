/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:54:53 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/14 21:14:39 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_str
{
		int		flag_hash;
		int		flag_zero;
		int		flag_minus;
		int		flag_space;
		int		flag_plus;
		int		flag_accuracy;
		int		accuracy;
		int		width;
		int		specif;
		int		exist;
		int		negative;
		int		extra_symbol;
		
}				t_str;

int			for_parse_width(t_str *str, va_list parametr, int start_flag);
const char	*parse_flag(const char *s, t_str *str);
const char	*parse_width(const char *s, t_str *str, va_list parametr);
const char	*parse_accuracy(const char *s, t_str *str, va_list parametr);
const char	*parse_specificator(const char *s, t_str *str);
int			whole_parser(const char *s, t_str *str, va_list parametr);
void		padding(int length, char c);
int			number_rank(unsigned long n, int base);
char		for_sign(t_str *str, long n);
int			str_len(t_str *str, int length, char *extra_symbols);
void		str_padding(t_str *str, int length, int str_length, int seg);
char		*ft_itoa_d(long n);
int			spec_d(t_str *str, va_list parametr);
int			spec_c(t_str *str, va_list parametr);
int			spec_s(t_str *str, va_list parametr);
int			spec_percent(t_str *str);
void		to_zero(t_str *str, int *count);
int			no_spec(const char *s);
int			spec_choose(t_str *str, va_list parametr);
int			ft_printf(const char *format, ...);

#endif 