/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_by_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:18:22 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:18:23 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap					*find_by_type(t_type type)
{
	t_heap				*heap;

	heap = singleton();
	while (heap)
	{
		if (heap->type == type)
			return (heap);
		heap = heap->next;
	}
	return (NULL);
}
