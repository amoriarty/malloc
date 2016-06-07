//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

t_block						*find_free(t_type type, size_t size)
{
	t_heap					*heap;
	t_block					*block;

	heap = singleton();
	while (heap)
	{
		if (heap->type == type)
		{
			block = heap->block;
			while (block)
			{
				if (block->free == TRUE && size <= block->size)
					return (block);
				block = block->next;
			}
		}
		heap = heap->next;
	}
	return (NULL);
}