/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 09:25:41 by alegent           #+#    #+#             */
/*   Updated: 2015/03/16 12:03:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_digitlen(int n)
{
	size_t				res;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	if (n > 9)
	{
		res++;
		return (res + ft_digitlen(n / 10));
	}
	res++;
	return (res);
}
