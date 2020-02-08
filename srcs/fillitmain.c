/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:48:09 by cyrmorin          #+#    #+#             */
/*   Updated: 2018/04/08 00:10:14 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_call_solver(t_piece *alst, int nb_piece, char **tab)
{
	int i;

	i = -1;
	tab = ft_post_cleaner(ft_solver(alst, nb_piece));
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		nb_piece;
	char	**tab;
	t_piece	*alst;
	int		*tab_valid;

	if (argc != 2)
	{
		ft_putstr("usage : fillit tetriminos_file");
		exit(0);
	}
	alst = NULL;
	i = -1;
	tab = ft_read_and_clean(argv, &nb_piece);
	while (tab[++i])
	{
		if ((tab_valid = ft_is_valid(tab[i])) == 0)
			ft_error();
		alst = ft_add_piece_to_list(ft_atoui_piece(tab_valid), alst);
	}
	ft_call_solver(alst, nb_piece, tab);
	return (0);
}
