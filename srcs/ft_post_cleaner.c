/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:05:57 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/02/06 20:06:00 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strcpy2(char *s1, const char *s2)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s2[size] != '\0')
		size++;
	while (i < size)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char		**ft_post_cleaner(char **map)
{
	int		i;
	char	**newmap;

	i = 0;
	while (ft_strlen(map[i]) != 0)
		i++;
	newmap = ft_double_memalloc(i, ft_strlen(map[0]));
	while (i >= 0)
	{
		newmap[i] = ft_strcpy2(newmap[i], map[i]);
		i--;
	}
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (newmap);
}
