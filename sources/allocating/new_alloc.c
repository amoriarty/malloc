//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

static t_heap				*init_heap(t_heap *heap, t_type type, size_t size)
{
	t_heap					*tmp;

	if (!(tmp = (t_heap *)ft_malloc(size)))
		return (NULL);
	tmp = new_heap(tmp, FALSE, size, type);
	push_heap(heap, tmp);
	return (tmp);
}

void						*new_large_alloc(size_t size)
{
	t_heap					*heap;

	if ((heap = init_heap(singleton(), LARGE, get_preload(size))))
	{
		heap->block->free = FALSE;
		return (heap->block->ptr);
	}
	return (NULL);
}

void						*new_alloc(size_t size, t_type type)
{
	t_block					*block;

	if (type == LARGE)
		return (new_large_alloc(size));
	if ((block = find_free(type, size)) != NULL)
	{
		block->free = FALSE;
		if (block->size != size)
			split_block(block, size);
		return (block->ptr);
	}
	if (init_heap(singleton(), type, get_preload(size)))
		return (new_alloc(size, type));
	return (NULL);
}