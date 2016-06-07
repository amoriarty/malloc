/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:28:40 by alegent           #+#    #+#             */
/*   Updated: 2016/04/27 10:28:41 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static char						*convert_long_base(unsigned long nbr)
{
	int						i;
	static char				*res;
	const char				*base;

	i = 8;
	if (!res)
		if (!(res = (char *)ft_malloc(sizeof(char) * 9)))
			return (NULL);
	ft_bzero(res, 9);
	base = "0123456789abcdef";
	while ((nbr / 16) > 0 || i >= 8)
	{
		res[i] = base[(nbr % 16)];
		nbr /= 16;
		i--;
	}
	res[i] = base[(nbr % 16)];
	return (res);
}

void							print_addr(void *ptr)
{
	ft_putstr("0x");
	ft_putstr(convert_long_base((unsigned long)ptr));
}
