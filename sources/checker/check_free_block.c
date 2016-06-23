/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:17:17 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:17:18 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				check_free_block(t_block *block)
{
	if (block->prev && block->prev->free == TRUE)
	{
		block->prev->size += BLOCK_SIZE + block->size;
		delete_block(block);
		check_free_block(block->prev);
	}
	else if (block->next && block->next->free == TRUE)
	{
		block->size += BLOCK_SIZE + block->next->size;
		delete_block(block->next);
		check_free_block(block);
	}
}
