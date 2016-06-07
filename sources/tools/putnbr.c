//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

void 					putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
		ft_putchar((char)(n + '0'));
}