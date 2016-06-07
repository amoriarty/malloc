//
// Created by Alexandre LEGENT on 02/06/2016.
//

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