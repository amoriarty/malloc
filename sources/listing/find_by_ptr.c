/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_by_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:18:10 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:18:11 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block					*find_by_ptr(void *ptr)
{
	t_heap				*heap;
	t_block				*block;

	heap = singleton();
	while (heap)
	{
		block = heap->block;
		while (block)
		{
			if (block->ptr == ptr)
				return (block);
			block = block->next;
		}
		heap = heap->next;
	}
	return (NULL);
}
