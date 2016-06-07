//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

size_t				get_preload(size_t size)
{
	if (size <= TINY_SIZE)
		return (PRELOAD_TINY);
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
		return (PRELOAD_SMALL);
	else
		return (LARGE_HEAP(size));
}