/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:16:44 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:16:45 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap			*new_heap(t_heap *new, t_bool lock, size_t size, t_type type)
{
	new->type = type;
	new->lock = lock;
	new->block = new_block((t_block *)new + HEAP_SIZE, size, TRUE);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
