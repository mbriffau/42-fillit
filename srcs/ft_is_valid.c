/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:55:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/05 18:05:34 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_is_valid_count(int *tab)
{
	int		count;

	count = 0;
	count = (tab[0] + 1 == tab[1] || tab[0] + 4 == tab[1])
		+ (tab[0] + 1 == tab[2] || tab[0] + 4 == tab[2])
		+ (tab[0] + 1 == tab[3] || tab[0] + 4 == tab[3])
		+ (tab[1] + 1 == tab[2] || tab[1] + 4 == tab[2])
		+ (tab[1] + 1 == tab[3] || tab[1] + 4 == tab[3])
		+ (tab[2] + 1 == tab[3] || tab[2] + 4 == tab[3]);
	if (count == 3 || count == 4)
		return (tab);
	return (0);
}

int		*ft_is_valid(char *s)
{
	int			i;
	int			j;
	int			*tab;

	i = 0;
	j = 0;
	if (!(tab = (int*)malloc(sizeof(int) * 4)))
		return (0);
	while (s[j] != '\0')
	{
		if (s[j] == '#')
		{
			tab[i] = j;
			i++;
		}
		j++;
	}
	if (i != 4)
		return (0);
	return (ft_is_valid_count(tab));
}
