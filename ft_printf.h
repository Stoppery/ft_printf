/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:54:53 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/12 17:17:10 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_str
{
		char	flag_hash;
		char	flag_zero;
		char	flag_minus;
		char	flag_space;
		char	flag_plus;
		char	flag_apostrophe;
		int		accuracy;
		int		width;
		
		
}				t_str;



#endif 