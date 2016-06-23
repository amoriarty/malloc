/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:00:55 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:00:56 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void						*malloc(size_t size)
{
	if ((int)size >= 0)
	{
		size = ptr_align(size);
		if (size <= TINY_SIZE)
			return (new_alloc(size, TINY));
		else if (size > TINY_SIZE && size <= SMALL_SIZE)
			return (new_alloc(size, SMALL));
		else
			return (new_alloc(size, LARGE));
	}
	return (NULL);
}
