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
#include <float.h>
#include "ft_printf.h"

int		main(void)
{
    int i;

    i = 0;

                printf("lib точность =   250 , %.16022Lf\n", LDBL_MIN);
    i = ft_printf("my точность =    250 , %.250f\n", LDBL_MIN);
    printf("\n");
    printf("lib точность =  0,      10999.9999979 = %.0f\n", 2.5);
    i = ft_printf("lib точность =  0,      10999.9999979 = %.0f\n", 2.5);
    printf("\n");
    printf("lib точность =   ,      10999.9999979 = %.f\n", 3.5);
    i = ft_printf("my точность =    ,      10999.9999979 = %.f\n", 3.5);
    printf("\n");
    printf("lib точность =  0,      10999.9999979 = %.0f\n", 3.5);
    i = ft_printf("lib точность =  0,      10999.9999979 = %.0f\n", 3.5);
    printf("\n");
    printf("lib точность =  1,      10999.9999979 = %.1f\n", 2.5);
    i = ft_printf("lib точность =  1,      10999.9999979 = %.1f\n", 2.5);
    printf("\n");
    printf("lib точность =  2,      10999.9999979 = %.2f\n", 2.5);
    i = ft_printf("my  точность =  2,      10999.9999979 = %.4f\n", 2.5);
    printf("\n");
    printf("lib точность =  3,      10999.9999979 = %.3f\n", 2.5);
    i = ft_printf("my  точность =  3,      10999.9999979 = %.3f\n", 2.5);
    printf("\n");
    printf("lib точность =  4,      10999.9999979 = %.4f\n", 2.5);
    i = ft_printf("my  точность =  4,      10999.9999979 = %.4f\n", 2.5);
    printf("\n");
    printf("lib точность =  5,      10999.9999979 = %.5f\n", 2.5);
    i = ft_printf("my  точность =  5,      10999.9999979 = %.5f\n", 2.5);
    printf("\n");
    printf("lib точность =  6,      10999.9999979 = %.6f\n", 2.5);
    i = ft_printf("my  точность =  6,      10999.9999979 = %.6f\n", 2.5);
    printf("\n");
    printf("lib точность =  7,      10999.9999979 = %.7f\n", 2.5);
    i = ft_printf("my  точность =  7,      10999.9999979 = %.7f\n", 2.5);
    printf("\n");
    printf("lib точность =  8,      10999.9999979 = %.8f\n", 2.5);
    i = ft_printf("my  точность =  8,      10999.9999979 = %.8f\n", 2.5);
    printf("\n");
    printf("lib точность =  9,      10999.9999979 = %.9f\n", 2.5);
    i = ft_printf("my  точность =  9,      10999.9999979 = %.9f\n", 2.5);
    printf("\n");
    printf("lib точность = 10,      10999.9999979 = %.10f\n", 10999.9999979);
    i = ft_printf("my  точность = 10,      10999.9999979 = %.10f\n", 10999.9999979);
    printf("\n");
    printf("lib точность = 11,      10999.9999979 = %.11f\n", 10999.9999979);
    i = ft_printf("my  точность = 11,      10999.9999979 = %.11f\n", 10999.9999979);
    printf("\n");
    printf("lib точность = 12,      10999.9999979 = %.12f\n", 10999.9999979);
    i = ft_printf("my  точность = 12,      10999.9999979 = %.12f\n", 10999.9999979);
    printf("\n");
    printf("lib точность = 13,      10999.9999979 = %.13f\n", 10999.9999979);
    i = ft_printf("my  точность = 13,      10999.9999979 = %.13f\n", 10999.9999979);

/*
	printf("lib точность = 2,      0.999999999999999 = %.2f\n", 10999.9);
    printf("lib точность = 2, 0.99999999999999999999999 = %.2f\n", 10999.99999999999999999999999);
    printf("------------------------------------------------------------------------------------------------------\n");
    i = ft_printf(" my точность = 2,      0.999999999999999 = %.2f\n",  10999.9);
    i = ft_printf(" my точность = 2, 0.99999999999999999999999 = %.2f\n",  10999.99999999999999999999999);

	//printf("%d", i);*/

    return (0);
}
