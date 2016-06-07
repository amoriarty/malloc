//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

size_t						ptr_align(size_t size)
{
	if (size % PTR_SIZE == 0)
		return (size);
	return (size - (size % PTR_SIZE) + PTR_SIZE);
}