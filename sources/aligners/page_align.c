//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

size_t					page_align(size_t size)
{
	int 				page_size;

	page_size = getpagesize();
	if (size % page_size == 0)
		return (size);
	return (size - (size % page_size) + page_size);
}