/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_align.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:01:33 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:20:35 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t						ptr_align(size_t size)
{
	if (size % PTR_SIZE == 0)
		return (size);
	return (size - (size % PTR_SIZE) + PTR_SIZE);
}
