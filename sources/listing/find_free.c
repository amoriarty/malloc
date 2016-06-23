/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:18:34 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:18:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block						*find_free(t_type type, size_t size)
{
	t_heap					*heap;
	t_block					*block;

	heap = singleton();
	while (heap)
	{
		if (heap->type == type)
		{
			block = heap->block;
			while (block)
			{
				if (block->free == TRUE && size <= block->size)
					return (block);
				block = block->next;
			}
		}
		heap = heap->next;
	}
	return (NULL);
}
