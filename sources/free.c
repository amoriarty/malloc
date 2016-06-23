/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:00:46 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:00:50 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					free(void *ptr)
{
	t_heap				*heap;
	t_block				*block;

	heap = singleton();
	while (heap)
	{
		block = heap->block;
		while (block)
		{
			if (block->ptr == ptr)
			{
				block->free = TRUE;
				check_free_block(block);
				check_free_heap(heap);
				return ;
			}
			block = block->next;
		}
		heap = heap->next;
	}
}
