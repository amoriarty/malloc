/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:01:10 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:22:06 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void				print_type(t_type type)
{
	if (type == TINY)
		ft_putstr("TINY");
	else if (type == SMALL)
		ft_putstr("SMALL");
	else if (type == LARGE)
		ft_putstr("LARGE");
}

static void				print_block(t_block *block)
{
	print_addr(block->ptr);
	ft_putstr(" - ");
	print_addr(block->ptr + block->size);
	ft_putstr(" : ");
	putnbr((int)block->size);
	ft_putendl(" octets");
}

static void				print_heap(t_heap *heap)
{
	print_type(heap->type);
	ft_putstr(": ");
	print_addr((void *)heap);
	ft_putchar(EOL);
}

void					show_alloc_mem(void)
{
	t_heap				*sglt;
	t_block				*block;
	size_t				total;

	total = 0;
	sglt = singleton();
	while (sglt)
	{
		print_heap(sglt);
		block = sglt->block;
		while (block)
		{
			if (block->free == FALSE)
			{
				print_block(block);
				total += block->size;
			}
			block = block->next;
		}
		sglt = sglt->next;
	}
	ft_putstr("Total : ");
	putnbr((int)total);
	ft_putendl(" octets");
}
