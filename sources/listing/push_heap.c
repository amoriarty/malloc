/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:18:57 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:24:09 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					push_heap(t_heap *heap, t_heap *new)
{
	t_heap				*tmp;

	if (heap)
	{
		tmp = heap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		heap = new;
}
