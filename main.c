#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int num = -1;
	char c;
	char *s;
	unsigned int u = 666;
	int numb = 777;
	int x = 667;
	int result;
	int zvezd = 23;

	c = 'y';
	s = "jopa";
	result = printf("Hello %% %c %s %u %d %i %x %X %p\n", c, s, u, num, num, num, numb, &num);
	printf("original return %d\n", result);
	result = ft_printf("Hello %% %c %s %u %d %i %x %X %p\n", c, s, u, num, num, num, numb, &num);
	printf("my return %d\n", result);

	printf("d-or %13.5d %-13.5d # %013.5d\n", numb, numb, numb);
	ft_printf("d-my %13.5d %-13.5d # %013.5d\n", numb, numb, numb);
	printf("i-or %13.2i %-13.5i %013.5i\n", numb, numb, numb);
	ft_printf("i-my %13.2i %-13.5i %013.5i\n", numb, numb, numb);
	printf("un-or %13.2u %-13.5u %013.5u\n", u, u, u);
	ft_printf("un-my %13.2u %-13.5u %013.5u\n", u, u, u);
	printf("c-or %13.2c %-13.5c %013.5c\n", c, c, c);
	ft_printf("c-my %13.2c %-13.5c %013.5c\n", c, c, c);
	result = printf("s-or %13.2s %-13.5s # %013.5s\n", s, s, s);
	printf("original return %d\n", result);
	result = ft_printf("s-my %13.2s %-13.5s # %013.5s\n", s, s, s);
	printf("my return %d\n", result);
	printf("x-or %13.2x %-13.5x %013.5x\n", x, x, x);
	ft_printf("x-my %13.2x %-13.5x %013.5x\n", x, x, x);
	printf("X-or %13.2X %-13.5X %013.5X\n", x, x, x);
	ft_printf("X-my %13.2X %-13.5X %013.5X\n", x, x, x);
	printf("p-or %23.2p %-23.5p %023p\n", &c, &c, &c);
	ft_printf("p-my %23.2p %-23.5p %023p\n", &c, &c, &c);

	printf("or %7.5s\n", "bombastic");
	ft_printf("my %7.5s\n", "bombastic");
	printf("or %-7.5s#\n", "tubular");
	ft_printf("my %-7.5s#\n", "tubular");
	printf("or hello, %s.\n", NULL);
	ft_printf("my hello, %s.\n", NULL);
	printf("or %p\n", NULL);
	ft_printf("my %p\n", NULL);
	printf("or %5p\n", 0);
	ft_printf("my %5p\n", 0);
	result = printf("or %-10.5i\n", -216);
	printf("return %d\n", result);
	result = ft_printf("my %-10.5i\n", -216);
	printf("return %d\n", result);
	printf("or %8.3i\n", -8473);
	ft_printf("my %8.3i\n", -8473);
	printf("%010.5i\n", -216);
	ft_printf("%010.5i\n", -216);
	printf("%10.5i\n", -216);
	ft_printf("%10.5i\n", -216);
	printf("or %.6d\n", -3);
	ft_printf("my %.6d\n", -3);
	printf("or %.0d\n", 5);
	ft_printf("my %.0d\n", 5);
	printf("or %.d\n", 0);
	ft_printf("my %.d\n", 0);
	printf("or %-*.*s\n", -7, -3, "yolo");
	ft_printf("my %-*.*s\n", -7, -3, "yolo");
	printf("%.p\n", NULL);
	ft_printf("%.p\n", NULL);
	printf("%5.p\n", 0);
	ft_printf("%5.p\n", 0);
	printf("%2.9p\n", 1234);
	ft_printf("%2.9p\n", 1234);
	printf("%09s\n", "hi low");
	ft_printf("%09s\n", "hi low");
	printf("%5\n", 0);
	ft_printf("%5\n", 0);
	printf("%*s\n", 3, "hello");
	ft_printf("%*s\n", 3, "hello");

	printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	
	printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|          |%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 0, 0, 0, 0, 0);
	ft_printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|         *|%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 0, 0, 0, 0, 0);

	printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|          |%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 234, 234, 234, 234, 234);
	ft_printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|         *|%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 234, 234, 234, 234, 234);

	printf("%%X.0_%%0.0X_%%3.0X_%%5.0X_%%10.0X|          |%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", -234, -234, -234, -234, -234);
	ft_printf("%%X.0_%%0.0X_%%3.0X_%%5.0X_%%10.0X|         *|%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", -234, -234, -234, -234, -234);

	printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|     |%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 0, 0, 0, 0, 0);
	ft_printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|    *|%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 0, 0, 0, 0, 0);

	printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|     |%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 234, 234, 234, 234, 234);
	ft_printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|    *|%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 234, 234, 234, 234, 234);

	printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|     |%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", -234, -234, -234, -234, -234);
	ft_printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|    *|%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", -234, -234, -234, -234, -234);

	printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");
	ft_printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");

	return (0);
}