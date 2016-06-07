//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

void 					push_heap(t_heap *heap, t_heap *new)
{
	t_heap				*tmp;

	if (heap)
	{
		tmp = heap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		heap = new;
}