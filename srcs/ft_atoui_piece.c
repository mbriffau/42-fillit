/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 01:16:35 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/05 18:04:01 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	*ft_top_left(size_t *tab)
{
	int		i;
	int		up;
	size_t	fst;
	size_t	tmp;

	fst = ft_pow(2, 31);
	up = 0;
	while (tab[up] == 0)
		up++;
	while (up--)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = tmp;
	}
	while (!(tab[0] & fst || tab[1] & fst || tab[2] & fst || tab[3] & fst))
	{
		i = 4;
		while (i)
			tab[--i] <<= 1;
	}
	return (tab);
}

size_t			*ft_atoui_piece(int *t)
{
	size_t	*tab;
	int		i;
	int		j;

	j = 0;
	i = 4;
	if (!(tab = (size_t*)malloc(sizeof(size_t) * 4)))
		return (0);
	while (i)
		tab[--i] = 0;
	while (j < 4)
	{
		if (i > 3 || j > 3)
			return (0);
		while (t[j] > 3)
		{
			t[j] -= 4;
			i++;
		}
		tab[i] += ft_pow(2, (31 - t[j]));
		i = 0;
		j++;
	}
	return (ft_top_left(tab));
}
