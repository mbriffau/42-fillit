/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_memalloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 21:13:17 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/22 21:13:19 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_double_memalloc(size_t strings, size_t stringsizes)
{
	char	**tab;
	size_t	i;

	tab = NULL;
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * strings + 1)))
		return (NULL);
	tab[strings] = 0;
	while (i < strings)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * stringsizes + 1)))
			return (NULL);
		ft_bzero(tab[i], stringsizes);
		tab[i][stringsizes] = '\0';
		i++;
	}
	return (tab);
}
