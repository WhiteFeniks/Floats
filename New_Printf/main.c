/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:51:04 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/12 17:55:41 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;

	i = 0;

	printf("lib точность = 2,      0.999999999999999 = %.2f\n", 10999.9);
    printf("lib точность = 2, 0.99999999999999999999999 = %.2f\n", 10999.99999999999999999999999);
    printf("------------------------------------------------------------------------------------------------------\n");
    i = ft_printf(" my точность = 2,      0.999999999999999 = %.2f\n",  10999.9);
    i = ft_printf(" my точность = 2, 0.99999999999999999999999 = %.2f\n",  10999.99999999999999999999999);

	//printf("%d", i);
	return (0);
}
