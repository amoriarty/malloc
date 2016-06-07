//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

t_heap					*find_last_heap(void)
{
	t_heap				*heap;

	heap = singleton();
	while (heap->next)
		heap = heap->next;
	return (heap);
}