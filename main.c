/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:33:34 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/07 19:58:51 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main ()
{

/* TEST FLOAT */
	printf("\n\n-------------TEST DTOA-------------\n");
	double	testd;
	float	testf;
	char	*tests;

	testd = 0.999999;
	testd = 2.123456789;
	testf = 2.123456789;
	tests = ft_dtoa((double)testf, 8);
	printf("tests = %s ; testd = %.8f ; testf = %.8f\n", tests, testd, testf);
	ft_strdel(&tests);
	tests = ft_dtoa((double)testd, 8);
	printf("tests = %s ; testd = %.8f\n", tests, testd);
	testd = 0.5555555555;
	ft_strdel(&tests);
	tests = ft_dtoa((double)testd, 8);
	printf("tests = %s ; testd = %.7f\n", tests, testd);
	testd = 2.999999000000000;
	printf("\n>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("testd = %.7f\n", testd);
	printf("testd = %.8f\n", testd);
	printf("testd = %.9f\n", testd);
	printf("testd = %.15f\n", testd);
	printf("testd = %.16f\n", testd);
	printf("testd = %.50f\n", testd);
	ft_strdel(&tests);
	tests = ft_dtoa((double)testd, 6);
	printf("tests = %s ; testd = %f\n", tests, testd);
	printf("\n-------------END TEST DTOA-------------\n\n");

	printf("-------------TEST PRINTF-------------\n");
	printf("\n--> Test 01 : nb arg > 10\n");
	printf("PRINTF:\narg 0 : %i ; arg 1 : %i ; arg 2 : %i ; arg 3 : %i ; arg 4 : %i ; arg 5 : %i ; arg 6 : %i ; arg 7 : %i ; arg 8 : %i ; arg 9 : %i ; arg 10 : %i\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	ft_printf("FT_PRINTF:\narg 0 : %i ; arg 1 : %i ; arg 2 : %i ; arg 3 : %i ; arg 4 : %i ; arg 5 : %i ; arg 6 : %i ; arg 7 : %i ; arg 8 : %i ; arg 9 : %i ; arg 10 : %i\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	printf("\n--> Test 02 : simple padding\n");
	printf("2.0 printf:\t|%5d| ; |%05d| ; |%-5d|\n", 2, 2, 2);
	ft_printf("2.0 ft_printf:\t|%5d| ; |%05d| ; |%-5d|\n", 2, 2, 2);

	printf("2.1 printf:\t|%+0d| ; |%+2d| ; |%0+5d|\n", 2, 2, 2);
	ft_printf("2.1 ft_printf:\t|%+0d| ; |%+2d| ; |%0+5d|\n", 2, 2, 2);
	
	printf("2.2 printf:\t|%+5d| ; |%-+5d| ; |%+-+-+-+--5d|\n", 2, 2, 2);
	ft_printf("2.2 ft_printf:\t|%+5d| ; |%-+5d| ; |%+-+-+-+--5d|\n", 2, 2, 2);
	
	printf("2.3 printf:\t|% d| ; |%0 5d| ; |%- 5d|\n", 2, 2, 2);
	ft_printf("2.3 ft_printf:\t|% d| ; |%0 5d| ; |%- 5d|\n", 2, 2, 2);
	
	printf("2.4 printf:\t|%5d| ; |%05d| ; |%-5d|\n", -2, -2, -2);
	ft_printf("2.4 ft_printf:\t|%5d| ; |%05d| ; |%-5d|\n", -2, -2, -2);
	
	printf("2.5 printf:\t|%+5d| ; |%+05d| ; |%+-5d|\n", -2, -2, -2);
	ft_printf("2.5 ft_printf:\t|%+5d| ; |%+05d| ; |%+-5d|\n", -2, -2, -2);
	
	printf("2.6 printf:\t+d : |%+d| ;  +5d : |%+5d| ; +-5d : |%+-5d| ; +05d : |%+05d|\n", 0, 0, 0, 0);
	ft_printf("2.6 ft_printf:\t+d : |%+d| ;  +5d : |%+5d| ; +-5d : |%+-5d| ; +05d : |%+05d|\n", 0, 0, 0, 0);

//	printf("printf:\t\t|%5s| ; |%05s| ; |%-5s|\n", "-2", "-2", "-2");
//	printf("printf:\t\t|%0-5d|\n", 2);
//	ft_printf("ft_printf:\t|%0-5d|\n", 2);

	printf("\n--> Test 03 : simple %%i et %%u\n");
	printf("printf:\n\tchaine de test %i suite %i\n", 2, -2);
	ft_printf("ft_printf:\n\tchaine de test %i suite %i\n", 2, -2);
	printf("printf:\n\tchaine de test %u suite %u\n", 3, -3);
	ft_printf("ft_printf:\n\tchaine de test %u suite %u\n", 3, -3);

	printf("\n--> Test 04 : test %%f\n");
	printf("4.1 printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123456789, 2., 0.01, 0., 0.0000001);
	ft_printf("4.1 ft_printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123456789, 2., 0.01, 0., 0.0000001);
	printf("4.2 printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123455789, 2.999999, 2.9999999, 9.9999999, 0.5555555);
	ft_printf("4.2 ft_printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123455789, 2.999999, 2.9999999, 9.9999999, 0.5555555);
	printf("4.3 printf:\t|%.0f| ; |%.0f| ; |%.0f| ; |%.0f| ; |%.0f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.4444444);
	ft_printf("4.3 ft_printf:\t|%.0f| ; |%.0f| ; |%.0f| ; |%.0f| ; |%.0f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.4444444);
	printf("4.4 printf:\t|%.2f| ; |%.1f| ; |%.8f| ; |%.10f| ; |%.6f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.5555555);
	ft_printf("4.4 ft_printf:\t|%.2f| ; |%.1f| ; |%.8f| ; |%.10f| ; |%.6f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.5555555);
	printf("4.5 printf:\t|%.12f| ; |%f| ; |%f|\n", 36.9999999999, 36.9999999999, -1.25);
	ft_printf("4.5 ft_printf:\t|%.12f| ; |%f| ; |%f|\n", 36.9999999999, 36.9999999999, -1.25);

	printf("\n--> Test 05 : precision with int\n");
	printf("5.1 printf:\t|%2d| ; |%.2d|\n", 2, 2);
	ft_printf("5.1 ft_printf:\t|%2d| ; |%.2d|\n", 2, 2);
	printf("5.2 printf:\t|%.2d| ; |%.2d| ; |%.2d|\n", 2, 20, -2);
	ft_printf("5.2 ft_printf:\t|%.2d| ; |%.2d| ; |%.2d|\n", 2, 20, -2);
	printf("5.3 printf:\t|%.2u| ; |%.2u| ; |%.2u|\n", 2, 20, -2);
	ft_printf("5.3 ft_printf:\t|%.2u| ; |%.2u| ; |%.2u|\n", 2, 20, -2);
	printf("5.4 printf:\t|%.0u| ; |%.1d| ; |%.7d| ; |%.20u|\n", 21, 21, 452, -2);
	ft_printf("5.4 ft_printf:\t|%.0u| ; |%.1d| ; |%.7d| ; |%.20u|\n", 21, 21, 452, -2);

	printf("\n--> Test 06 : precision + width with int\n");
	printf("6.1 printf:\t|%2.0d| ; |%2.2d| ; |%2.3d| ; |%5.3d|\n", 2, 2, 2, 2);
	ft_printf("6.1 ft_printf:\t|%2.0d| ; |%2.2d| ; |%2.3d| ; |%5.3d|\n", 2, 2, 2, 2);
	printf("6.2 printf:\t|%-2.0d| ; |%-2.2d| ; |%-2.3d| ; |%-5.3d|\n", 2, 2, 2, 2);
	ft_printf("6.2 ft_printf:\t|%-2.0d| ; |%-2.2d| ; |%-2.3d| ; |%-5.3d|\n", 2, 2, 2, 2);

	printf("\n--> Test 07 : test string\n");
	printf("7.1 printf:\t|%s| ; |%-s|\n", "chaine de test", "-s");
	ft_printf("7.1 ft_printf:\t|%s| ; |%-s|\n", "chaine de test", "-s");
	printf("7.2 printf:\t|%-12s| ; |%-.5s|\n", "**:)**", "-s");
	ft_printf("7.2 ft_printf:\t|%-12s| ; |%-.5s|\n", "**:)**", "-s");
//	printf("7.3 printf:\t|%+-12s| ; |%0-10.5s|\n", "**:)**", "-s");
//	ft_printf("7.3 ft_printf:\t|%+-12s| ; |%0-10.5s|\n", "**:)**", "-s");
	printf("7.4 printf:\t|%-12s| ; |%1s|\n", "", "s#$-s");
	ft_printf("7.4 ft_printf:\t|%-12s| ; |%1s|\n", "", "s#$-s");

	printf("\n--> Test 08 : test hexa\n");
	printf("8.1 printf:\t|%x| ; |%X|\n", 12, 12);
	ft_printf("8.1 ft_printf:\t|%x| ; |%X|\n", 12, 12);
	printf("8.2 printf:\t|%x| ; |%X|\n", -12, -8);
	ft_printf("8.2 ft_printf:\t|%x| ; |%X|\n", -12, -8);
	printf("8.3 printf:\t|%x| ; |%X|\n", 0, -1);
	ft_printf("8.3 ft_printf:\t|%x| ; |%X|\n", 0, -1);
//	printf("8.4 printf:\t|%X| ; |%X| ; |%X|\n", 4294967295, -1, -2);
//	ft_printf("8.4 ft_printf:\t|%X| ; |%X| ; |%X|\n", 4294967295, -1, -2);
	printf("8.5 printf:\t|%.10x| ; |%.1x|\n", 45612, 45612);
	ft_printf("8.5 ft_printf:\t|%.10x| ; |%.1x|\n", 45612, 45612);
	printf("8.6 printf:\t|%15x| ; |%1x|\n", 45612, 45612);
	ft_printf("8.6 ft_printf:\t|%15x| ; |%1x|\n", 45612, 45612);
//	printf("8.7 printf:\t|%-15x| ; |%+1x|\n", 45612, 45612);
//	ft_printf("8.7 ft_printf:\t|%-15x| ; |%+1x|\n", 45612, 45612);
//	printf("8.8 printf:\t|%015x| ; |%0-15x|\n", 45612, 45612);
//	ft_printf("8.8 ft_printf:\t|%015x| ; |%0-15x|\n", 45612, 45612);

	printf("\n--> Test 09 : test octal\n");
	printf("9.1 printf:\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	ft_printf("9.1 ft_printf:\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	printf("9.2 printf:\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	ft_printf("9.2 ft_printf:\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	printf("9.3 printf:\t|%o| ; |%o|\n", 0, -1);
	ft_printf("9.3 ft_printf:\t|%o| ; |%o|\n", 0, -1);
//	printf("9.4 printf:\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
//	ft_printf("9.4 ft_printf:\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
	printf("9.5 printf:\t|%.10o| ; |%.1o|\n", 45612, 45612);
	ft_printf("9.5 ft_printf:\t|%.10o| ; |%.1o|\n", 45612, 45612);
	printf("9.6 printf:\t|%15o| ; |%1o|\n", 45612, 45612);
	ft_printf("9.6 ft_printf:\t|%15o| ; |%1o|\n", 45612, 45612);
//	printf("9.7 printf:\t|%-15o| ; |%+1o|\n", 45612, 45612);
//	ft_printf("9.7 ft_printf:\t|%-15o| ; |%+1o|\n", 45612, 45612);
//	printf("9.8 printf:\t|%015o| ; |%0-15o|\n", 45612, 45612);
//	ft_printf("9.8 ft_printf:\t|%015o| ; |%0-15o|\n", 45612, 45612);

	printf("\n-------------END TEST PRINTF-------------\n");

	while (1)
	{}

	return (0);
}
