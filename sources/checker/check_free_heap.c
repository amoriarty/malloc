//
// Created by Alexandre LEGENT on 03/06/2016.
//

#include "malloc.h"

void				check_free_heap(t_heap *heap)
{
	t_block				*block;

	if (heap->lock == FALSE)
	{
		block = heap->block;
		if (!(block->next) && !(block->prev) && block->free == TRUE)
			delete_heap(heap);
	}
}