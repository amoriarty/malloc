/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:16:57 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:16:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					split_block(t_block *block, size_t size)
{
	t_block					*new;

	new = new_block(block->ptr + size, block->size - size, TRUE);
	block->size = size;
	push_block(block, new);
}
