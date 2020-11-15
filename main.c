/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:44:02 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/15 19:26:37 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(){
	int data = 29;
    ft_printf("МОЯ: %x\n", data);
	printf("%x\n", data);
    ft_printf("МОЯ: %0x\n", data);
	printf("%0x\n", data);
    ft_printf("МОЯ: %8x\n", data);
	printf("%8x\n", data);
    ft_printf("МОЯ: %08x\n\n\n", data);
	printf("%08x\n\n\n", data);
	return (1);
}
