/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_heap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:17:28 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:17:28 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				check_free_heap(t_heap *heap)
{
	t_block				*block;

	if (heap->lock == FALSE)
	{
		block = heap->block;
		if (!(block->next) && !(block->prev) && block->free == TRUE)
			delete_heap(heap);
	}
}
