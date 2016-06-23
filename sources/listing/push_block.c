/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:18:50 by alegent           #+#    #+#             */
/*   Updated: 2016/06/23 11:23:45 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					push_block(t_block *block, t_block *new)
{
	t_block				*tmp;

	if (block)
	{
		tmp = block;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		block = new;
}
