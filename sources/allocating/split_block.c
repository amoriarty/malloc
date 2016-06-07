//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

void					split_block(t_block *block, size_t size)
{
	t_block					*new;

	new = new_block(block->ptr + size, block->size - size, TRUE);
	block->size = size;
	push_block(block, new);
}