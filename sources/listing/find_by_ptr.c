//
// Created by Alexandre LEGENT on 03/06/2016.
//

#include "malloc.h"

t_block					*find_by_ptr(void *ptr)
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
				return (block);
			block = block->next;
		}
		heap = heap->next;
	}
	return (NULL);
}