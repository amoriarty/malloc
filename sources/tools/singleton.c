//
//           :::      ::::::::
//         :+:      :+:    :+:     singleton.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 6/1/16 2:05 PM by alegent
//

#include "malloc.h"

static t_heap			*init_heap(void)
{
	void 				*ptr;
	t_heap				*init;

	if (!(ptr = ft_malloc(page_align(PRELOAD_TINY + PRELOAD_SMALL))))
		return (NULL);
	init = new_heap((t_heap *)ptr, TRUE, PRELOAD_ITERATE * TINY_SIZE, TINY);
	ptr = init->block->ptr + PRELOAD_ITERATE * (BLOCK_SIZE + TINY_SIZE);
	push_heap(init, new_heap((t_heap *)ptr, TRUE, PRELOAD_ITERATE * SMALL_SIZE, SMALL));
	return (init);
}

t_heap					*singleton(void)
{
	static t_heap		*heap;

	if (!heap)
		heap = init_heap();
	return (heap);
}