//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

void				delete_block(t_block *block)
{
	if (block->prev)
		block->prev->next = block->next;
	if (block->next)
		block->next->prev = block->prev;
}