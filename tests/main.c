//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"


int 						main(void)
{
	char					*ptr;
	t_heap					*sglt;

	sglt = singleton();
	for (int i = 0; i < 2496; i++)
	{
		ptr = malloc(400000);
		free(ptr);

	}
	return (EXIT_SUCCESS);

	/*
	for (int i = 0; i < 160; i++)
	{
		ptr = malloc(TINY_SIZE);
		if (ptr)
		{
			*(int *)ptr = 42;
			putnbr(i);
			ft_putchar(EOL);
		}
	}

	for (int i = 0; i < 160; i++)
	{
		ptr = malloc(SMALL_SIZE);
		if (ptr)
		{
			*(int *)ptr = 42;
			putnbr(i);
			ft_putchar(EOL);
		}
	}

	for (t_heap *heap = sglt; heap; heap = heap->next)
	{
		switch (heap->type)
		{
			case TINY:
				ft_putendl("TINY");
				break;
			case SMALL:
				ft_putendl("SMALL");
				break;
		}
		for (t_block *block = heap->block; block; block = block->next)
		{
			putnbr((int)block->size);
			ft_putchar(EOL);
		}
	}


	t_heap					*sglt;
	t_block					*block;
	t_block					*tmp;
	void 					*ptr;

	sglt = singleton();
	block = sglt->block;
	ptr = block->ptr;

	for (size_t i = 0; i < 99; i++)
	{
		printf("%lu\n", i);
		ptr += TINY_SIZE;
		tmp = new_block(ptr, TINY_SIZE, TRUE);
		push_block(block, tmp);
		ptr += BLOCK_SIZE;
	}

	return (EXIT_SUCCESS);
	*/

	/*
	t_heap					*heap;
	size_t 					tiny_preload = (BLOCK_SIZE + TINY_SIZE) * PRELOAD_ITERATE;
	size_t 					small_preload = (BLOCK_SIZE + SMALL_SIZE) * PRELOAD_ITERATE;

	ptr = ft_malloc(HEAP_SIZE + tiny_preload + small_preload);
	heap = (t_heap *)ptr;
	heap->lock = TRUE;
	heap->next = NULL;
	heap->prev = NULL;
	heap->type = SMALL;
	heap->block = (t_block *)(ptr + HEAP_SIZE);
	heap->block->next = NULL;
	heap->block->prev = NULL;
	heap->block->free = FALSE;
	heap->block->size = 4;
	heap->block->ptr = (void *)(heap->block + BLOCK_SIZE);
	heap->next = (t_heap *)(heap->block->ptr + (BLOCK_SIZE + SMALL_SIZE) * (PRELOAD_ITERATE - 1));
	heap->next->lock = TRUE;
	heap->next->next = NULL;
	heap->next->prev = heap;
	heap->next->type = TINY;
	heap->next->block = (t_block *)(heap->next + HEAP_SIZE);
	heap->next->block->next = NULL;
	heap->next->block->prev = NULL;
	heap->next->block->free = FALSE;
	heap->next->block->size = 2048;
	heap->next->block->ptr = (void *)(heap->next->block + BLOCK_SIZE);
	*/
}