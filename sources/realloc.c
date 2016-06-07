//
// Created by Alexandre LEGENT on 03/06/2016.
//

#include "malloc.h"

static void		*memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

void							*realloc(void *ptr, size_t size)
{
	void						*new;
	t_block						*block;

	if (!ptr)
		return (malloc(size));
	if ((int)size <= 0)
		free(ptr);
	else if ((block = find_by_ptr(ptr)))
	{
		size = ptr_align(size);
		check_free_block(block);
		if (size == block->size)
			return (block->ptr);
		else if (size < block->size)
		{
			split_block(block, size);
			return (block->ptr);
		}
		else if ((new = malloc(size)))
		{
			memcpy(new, ptr, size);
			free(ptr);
			return (new);
		}
	}
	return (NULL);
}