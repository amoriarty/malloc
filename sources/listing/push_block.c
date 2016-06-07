//
// Created by Alexandre LEGENT on 02/06/2016.
//

#include "malloc.h"

void 					push_block(t_block *block, t_block *new)
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