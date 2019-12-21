/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:51:04 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 13:22:29 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <float.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#include <float.h>
#include <termios.h>
#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

#define LDBL_INF   0x7FFF0000000000000000L
#define LDBL_NINF  0xFFFF0000000000000000L
#define LDBL_NAN   0x7FFF0000000001000000L
#define LDBL_PZERO 0x00000000000000000000L
#define LDBL_NZERO 0x80000000000000000000L
int		main(void)
{
    int i;

    i = 0;
/*
    printf("lib %5.1f\n", -7.3);
    i = ft_printf("my  %5.1f\n", -7.3);
    printf("\n");

    printf("lib %Llf\n", 42.5);
    i = ft_printf("my  %Llf\n", 42.5);
    printf("\n");*/
/*
    printf("l = %d\n", printf("%2c", 0));
    printf("m = %d\n",(i = ft_printf("%2c", 0)));
    printf("\n");
*/
/*  printf("l = %d\n", printf("%s %s", "this", "is"));
    printf("m = %d\n",(i = ft_printf("%s %s", "this", "is")));
    printf("\n"); */

    /*printf("l = %d\n", printf("@moulitest: %.d %.0d", 42, 43));
    printf("m = %d\n",(i = ft_printf("@moulitest: %.d %.0d", 42, 43)));
    printf("\n");*/
/*
    printf("l %.0d\n", 56);
    ft_printf("m %.0d\n", 56);

    printf("\n");
    printf("l %.0d\n", 0);
    ft_printf("m %.0d\n", 0);*/

    printf("\n");
    printf("l %u\n", -1);
    ft_printf("m %u\n", -1);



/*
    printf("Lib %Lf\n", 42.5l);
    i = ft_printf("My  %Lf\n", 42.5l);
    printf("\n");
*/
  /*  printf("l %d \n", printf("@moulitest: %#.x %#.0x", 0, 0));
    printf("m %d \n", ft_printf("@moulitest: %#.x %#.0x", 0, 0));
    printf("\n");
    printf("l %d \n", printf("%x\n", 4294967296));
    printf("m %d \n", ft_printf("%x\n", 4294967296)); */
   /* printf("\n");
    printf("l %d \n", printf("@moulitest: %.5u\n", 42));
    printf("m %d \n", ft_printf("@moulitest: %.5u\n", 42));    */
   /* printf("\n");
    printf("l %d \n", printf("%lu\n", -42));
    printf("m %d \n", ft_printf("%lu\n", -42));*/
   /* printf("\n");
    printf("l %d \n", printf("%u\n", -1));
    printf("m %d \n", ft_printf("%u\n", -1));    */
    /*printf("\n");
    printf("l %d \n", printf("@moulitest: %5.d %5.0d\n", 0, 0));
    printf("m %d \n", ft_printf("@moulitest: %5.d %5.0d\n", 0, 0));
*/
//tests good Polina
/*
ft_printf("m0 %x\n", -42);
ft_printf("l0 %x\n", -42);
printf("\n");
ft_printf("m1 %X\n", -42);
ft_printf("l1 %X\n", -42);
printf("\n");
ft_printf("m2 %x\n", 4294967296);
printf("l2 %lx\n", 4294967296);
printf("\n");
ft_printf("m3 %X\n", 4294967296);
printf("l3 %lX\n", 4294967296);
printf("\n");
ft_printf("m4 %hx\n", 4294967296);
printf("l4 %lx\n", 4294967296);
printf("\n");
ft_printf("m5 %hhX\n", 4294967296);
printf("l5 %lX\n", 4294967296);
printf("\n");*/




  /*  int x;

    x = 0;
    while(i = ft_printf("%f\n", NULL))
    {
        x++;
    }*/

    int x;

    x = 0;
    while(ft_printf("m %u\n", -1))
    {
        x++;
    }

    //printf("lib %u\n", 4295845319);
    //i = ft_printf("my  %u\n", 4295845319);
   //printf("\n");

 /*   int x;

    x = 0;
    while(i = ft_printf("my  %u\n", 878023))
    {
        x++;
    }*/
/*
    printf("lib точность =  DBL_MAX, %.700f\n", DBL_MAX);
    i = ft_printf("my точность =   DBL_MIN, %.700f\n", DBL_MAX);
    printf("\n");

    printf("lib точность =  INF, %.700f\n", 1.0/0.0);
    i = ft_printf("my точность =   INF, %.700f\n", 1.0/0.0);
    printf("\n");*/
    /*printf("lib точность =  0,      10999.9999979 = %.0f\n", 2.5);
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
*/
/*
	printf("lib точность = 2,      0.999999999999999 = %.2f\n", 10999.9);
    printf("lib точность = 2, 0.99999999999999999999999 = %.2f\n", 10999.99999999999999999999999);
    printf("------------------------------------------------------------------------------------------------------\n");
    i = ft_printf(" my точность = 2,      0.999999999999999 = %.2f\n",  10999.9);
    i = ft_printf(" my точность = 2, 0.99999999999999999999999 = %.2f\n",  10999.99999999999999999999999);

	//printf("%d", i);*/

    return (0);
}
