/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:01:03 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 12:20:02 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void						*memcpy(void *dst, const void *src, size_t n)
{
	size_t						i;

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
	if ((int)size < 0)
		free(ptr);
	else if ((block = find_by_ptr(ptr)))
	{
		check_free_block(block);
		if ((size = ptr_align(size)) == block->size)
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
