/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpiece_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:26:39 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/03 20:29:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_tpiece_to_char2(int *i, int *j, int *power, t_piece *piece)
{
	*j = 0;
	while (*j < 4)
	{
		if (ft_pow(2, *power) & piece->tab[*i])
		{
			piece->chartab[*i][*j] = piece->letter;
			*power -= 1;
		}
		else
		{
			piece->chartab[*i][*j] = '.';
			*power -= 1;
		}
		*j = *j + 1;
	}
}

t_piece		*ft_tpiece_to_char(t_piece *piece)
{
	int		i;
	int		j;
	int		power;

	power = 31;
	j = 0;
	i = 0;
	piece->tab[0] <<= piece->shift_x;
	piece->tab[1] <<= piece->shift_x;
	piece->tab[2] <<= piece->shift_x;
	piece->tab[3] <<= piece->shift_x;
	while (i < 4)
	{
		if (piece->tab[i] == 0)
			piece->chartab[i] = "....\0";
		else
		{
			ft_tpiece_to_char2(&i, &j, &power, piece);
		}
		power = 31;
		i++;
	}
	return (piece);
}
