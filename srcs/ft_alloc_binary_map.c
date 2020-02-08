/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_binary_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:37:26 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/06 17:54:30 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	*ft_alloc_binary_map(size_t *binary_map)
{
	size_t		*copy_binary_map;
	int			i;

	i = 0;
	if (!(copy_binary_map = (size_t*)malloc(sizeof(size_t) * 13)))
		return (0);
	while (i < 13)
	{
		copy_binary_map[i] = binary_map[i];
		i++;
	}
	return (copy_binary_map);
}
