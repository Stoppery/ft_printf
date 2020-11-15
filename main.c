/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:44:02 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/15 20:51:20 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(){
	int data = 29;
    ft_printf("%0*i\n", -7, -54);
	printf("%0*i\n", -7, -54);

	
    // ft_printf("МОЯ: %0x\n", data);
	// printf("111: %0x\n", data);
    // ft_printf("МОЯ: %8x\n", data);
	// printf("111: %8x\n", data);
    // ft_printf("МОЯ: %08x\n", data);
	// printf("111: %08x\n", data);
	return (1);
}
