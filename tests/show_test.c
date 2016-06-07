/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:01:12 by alegent           #+#    #+#             */
/*   Updated: 2016/04/27 12:32:37 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** export DYLD_LIBRAIRY_PATH=.
** export DYLD_INSERT_LIBRAIRIES=libft_malloc.so
*/

#include <stdio.h>
#include "malloc.h"

int							main(void)
{
	printf("\nShow_alloc_mem():\n");
	printf("Reference:\n\
TINY : 0xA0000\n\
0xA0020 - 0xA004A : 16 octets\n\
0xA006A - 0xA00BE : 1024 octets\n\
SMALL : 0xAD000\n\
0xAD020 - 0xADEAD : 3725 octets\n\
LARGE : 0xB0000\n\
0xB0020 - 0xBBEEF : 48847 octets\n\
Total : 53612 octets\n\
			\n");
	malloc(16);
	malloc(1024);
	malloc(3725);
	malloc(48847);
	show_alloc_mem();
	return (EXIT_SUCCESS);
}
