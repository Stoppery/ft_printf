/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:54:53 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/13 20:09:39 by dsherie          ###   ########.fr       */
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
		
}				t_str;

int			for_parse_width(t_str *str, va_list parametr, int start_flag);
const char	*parse_flag(const char *s, t_str *str);
const char	*parse_width(const char *s, t_str *str, va_list parametr);
const char	*parse_accuracy(const char *s, t_str *str, va_list parametr);
const char	*parse_specificator(const char *s, t_str *str);
int			whole_parser(const char *s, t_str *str, va_list parametr);
void		to_zero(t_str *str, int *count);
int			no_spec(const char *s);
int			ft_printf(const char *format, ...);

#endif 