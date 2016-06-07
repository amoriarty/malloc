//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

t_block					*new_block(t_block *new, size_t size, t_bool free)
{
	new->free = free;
	new->size = size;
	new->ptr = (void *)new + BLOCK_SIZE;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}