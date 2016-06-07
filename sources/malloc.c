//
// Created by Alexandre LEGENT on 31/05/2016.
//
#include "malloc.h"

void						*malloc(size_t size)
{
	if ((int)size >= 0)
	{
		size = ptr_align(size);
		if (size <= TINY_SIZE)
			return (new_alloc(size, TINY));
		else if (size > TINY_SIZE && size <= SMALL_SIZE)
			return (new_alloc(size, SMALL));
		else
			return (new_alloc(size, LARGE));
	}
	return (NULL);
}