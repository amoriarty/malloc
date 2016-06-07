//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

t_heap			*new_heap(t_heap *new, t_bool lock, size_t size, t_type type)
{
	new->type = type;
	new->lock = lock;
	new->block = new_block((t_block *)new + HEAP_SIZE, size, TRUE);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}