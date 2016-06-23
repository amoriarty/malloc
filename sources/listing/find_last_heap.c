/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_heap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:18:41 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:18:42 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap					*find_last_heap(void)
{
	t_heap				*heap;

	heap = singleton();
	while (heap->next)
		heap = heap->next;
	return (heap);
}
