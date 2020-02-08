/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:40:11 by cyrmorin          #+#    #+#             */
/*   Updated: 2016/11/07 18:40:13 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *buff;

	buff = (void *)malloc(sizeof(void*) * size);
	if (buff)
	{
		ft_memset(buff, 0, size);
		return (buff);
	}
	else
		return (NULL);
}
