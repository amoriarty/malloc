/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:19:16 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:47:13 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void								*ft_malloc(size_t size)
{
	void							*ptr;

	ptr = mmap(NULL, size, PROT_CONF, FLAG_CONF, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}
