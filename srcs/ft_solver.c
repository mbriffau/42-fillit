/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:01:23 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/06 18:26:58 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_cmp_piece(t_piece *piece)
{
	if (piece->tab[0] == piece->next->tab[0]
			&& piece->tab[1] == piece->next->tab[1]
			&& piece->tab[2] == piece->next->tab[2]
			&& piece->tab[3] == piece->next->tab[3])
		return (1);
	return (0);
}

static size_t		*ft_b_add(size_t *b_map, t_piece *add)
{
	int		i;
	size_t	*tmp;

	if (add == 0)
		return (0);
	if (!(tmp = (size_t*)malloc(sizeof(size_t) * 13)))
		return (0);
	i = 0;
	while (i < 13)
	{
		tmp[i] = b_map[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tmp[add->shift_y + i] += add->tab[i];
		i++;
	}
	return (tmp);
}

static char			**ft_solver2(size_t *b_map, t_piece *new,
	char **map_char, int lt)
{
	size_t		*cp_bmap;
	t_piece		*cp_new;
	int			i;

	i = 0;
	if ((cp_bmap = ft_alloc_binary_map(b_map)) == 0
		|| (cp_new = ft_lstcopy(new)) == 0)
		return (0);
	while (1)
	{
		if (i)
		{
			if ((new->next == NULL)
				|| (ft_solver2(cp_bmap, new->next, map_char, lt) != 0))
				return (ft_add_char(map_char, ft_tpiece_to_char(cp_new)));
			if (ft_cmp_piece(new))
				return (0);
			ft_binary_tool(cp_new, 1);
		}
		if ((cp_bmap = ft_b_add(b_map, ft_s_bslot(b_map, cp_new, lt))) == 0)
			return (0);
		i = 1;
	}
	return (0);
}

static int			ft_solve_it(t_piece *alst, char **map_char,
								int *lt, size_t *b_map)
{
	int i;

	i = 0;
	if ((ft_solver2(b_map, alst, map_char, *lt)) != 0)
		return (1);
	else
	{
		*lt = *lt + 1;
		i = 0;
		while (i < (*lt - 1))
		{
			ft_memset(map_char[i], '.', (*lt - 1));
			i++;
		}
		return (0);
	}
}

char				**ft_solver(t_piece *alst, int nb_piece)
{
	size_t	*b_map;
	char	**map_char;
	int		i;
	int		lt;
	int		ok;

	i = 0;
	ok = 0;
	lt = (ft_sqrt_sup(nb_piece * 4) + 1);
	if (!(b_map = malloc(sizeof(size_t) * 14)))
		return (0);
	if (!(map_char = ft_double_memalloc(21, 21)))
		return (0);
	while (i < 14)
		b_map[i++] = 0;
	i = 0;
	while (i < (lt - 1))
	{
		ft_memset(map_char[i], '.', (lt - 1));
		i++;
	}
	while (!(ok))
		ok = ft_solve_it(alst, map_char, &lt, b_map);
	return (map_char);
}
