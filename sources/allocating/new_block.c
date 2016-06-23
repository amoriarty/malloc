/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:02:06 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:02:07 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block					*new_block(t_block *new, size_t size, t_bool free)
{
	new->free = free;
	new->size = size;
	new->ptr = (void *)new + BLOCK_SIZE;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
