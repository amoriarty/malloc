//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

void					delete_heap(t_heap *heap)
{
	if (heap->prev)
		heap->prev->next = heap->next;
	if (heap->next)
		heap->next->prev = heap->prev;
	munmap(heap, HEAP_SIZE + BLOCK_SIZE + heap->block->size);
}