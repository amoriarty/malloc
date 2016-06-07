//
//           :::      ::::::::
//         :+:      :+:    :+:     ft_malloc.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 6/1/16 2:07 PM by alegent
//

#include "malloc.h"

void 								*ft_malloc(size_t size)
{
	void							*ptr;

	ptr = mmap(NULL, size, PROT_CONF, FLAG_CONF, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}