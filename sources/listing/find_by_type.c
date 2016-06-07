//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

t_heap					*find_by_type(t_type type)
{
	t_heap				*heap;

	heap = singleton();
	while (heap)
	{
		if (heap->type == type)
			return (heap);
		heap = heap->next;
	}
	return (NULL);
}