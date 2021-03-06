/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:01:54 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:23:25 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t				get_size(t_type type, size_t size)
{
	if (type == TINY)
		return (PRELOAD_ITERATE * TINY_SIZE);
	else if (type == SMALL)
		return (PRELOAD_ITERATE * SMALL_SIZE);
	return (size);
}

static t_heap				*init_heap(t_heap *heap, t_type type, size_t size)
{
	t_heap					*tmp;

	if (!(tmp = (t_heap *)ft_malloc(size + getpagesize())))
		return (NULL);
	tmp = new_heap(tmp, FALSE, get_size(type, size), type);
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
