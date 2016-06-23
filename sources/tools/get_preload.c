/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_preload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:19:22 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:19:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t				get_preload(size_t size)
{
	if (size <= TINY_SIZE)
		return (PRELOAD_TINY);
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
		return (PRELOAD_SMALL);
	else
		return (LARGE_HEAP(size));
}
