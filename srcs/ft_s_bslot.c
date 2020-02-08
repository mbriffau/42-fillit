/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_binary_slot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 00:52:19 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/06 18:09:49 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece			*ft_binary_tool(t_piece *piece, int n)
{
	int		i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1;
		while (i < 4)
			piece->tab[i++] <<= n;
		if ((piece->shift_x -= n) == 0)
			piece->shift_y += 1;
	}
	else
	{
		while (i < 4)
			piece->tab[i++] >>= n;
		piece->shift_x += n;
	}
	return (piece);
}

static t_piece	*ft_check_binary_mask(size_t *map, t_piece *piece)
{
	if (map[piece->shift_y + 0] & piece->tab[0] || map[piece->shift_y + 1]
		& piece->tab[1] || map[piece->shift_y + 2] & piece->tab[2] ||
		map[piece->shift_y + 3] & piece->tab[3])
		return (ft_binary_tool(piece, 1));
	else
		return (0);
}

static t_piece	*ft_check_limit_x(t_piece *piece, int limit)
{
	int		lmtbit;

	lmtbit = (1 << (31 - (limit - 1)));
	if ((piece->tab[0] & lmtbit || piece->tab[1] & lmtbit ||
		piece->tab[2] & lmtbit || piece->tab[3] & lmtbit))
		return (ft_binary_tool(piece, -(piece->shift_x)));
	return (0);
}

static int		ft_check_limit_y(t_piece *piece, int limit)
{
	if (((piece->shift_y + piece->size) >= limit))
		return (1);
	return (0);
}

t_piece			*ft_s_bslot(size_t *map, t_piece *piece, int limit)
{
	int			x;

	x = 1;
	while ((piece->tab[piece->size] & 4294967295) && piece->size < 4)
		piece->size += 1;
	while (x)
	{
		if ((ft_check_binary_mask(map, piece) == 0)
			&& (ft_check_limit_x(piece, limit) == 0))
			x = 0;
		if (ft_check_limit_y(piece, limit))
			return (0);
	}
	return (piece);
}
