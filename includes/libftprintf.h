/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:54:53 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/13 17:55:50 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
		
}				t_str;

int			for_parse_width(t_str *str, va_list ap, int start_flag);
const char	*parse_flag(const char *s, t_str *str);
const char	*parse_width(const char *s, t_str *str, va_list ap);
const char	*parse_accuracy(const char *s, t_str *str, va_list ap);
const char	*parse_specificator(const char *s, t_str *str);
int			whole_parser(const char *s, t_str *str, va_list ap);
void		if_zero(t_str *block, int *count);
int			ft_printf(const char *format, ...);

#endif 