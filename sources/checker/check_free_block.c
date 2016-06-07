//
// Created by Alexandre LEGENT on 03/06/2016.
//

#include "malloc.h"

void				check_free_block(t_block *block)
{
	if (block->prev && block->prev->free == TRUE)
	{
		block->prev->size += BLOCK_SIZE + block->size;
		delete_block(block);
		check_free_block(block->prev);
	}
	else if (block->next && block->next->free == TRUE)
	{
		block->size += BLOCK_SIZE + block->next->size;
		delete_block(block->next);
		check_free_block(block);
	}
}