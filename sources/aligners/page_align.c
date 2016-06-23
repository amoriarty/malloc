/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_align.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:01:25 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:21:08 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t					page_align(size_t size)
{
	int					page_size;

	page_size = getpagesize();
	if (size % page_size == 0)
		return (size);
	return (size - (size % page_size) + page_size);
}
