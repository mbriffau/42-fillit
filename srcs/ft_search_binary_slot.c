/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_binary_slot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 00:52:19 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/27 23:17:02 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_binary_mask(size_t *binary_map, t_piece *add)/*verifie si les deux pieces se chevauchent.*/
{/*fonction verifie c'est OK*/
	if (binary_map[add->shift_y + 0] & add->tab[0] || binary_map[add->shift_y + 1] & add->tab[1]
	 || binary_map[add->shift_y + 2] & add->tab[2] || binary_map[add->shift_y + 3] & add->tab[3])
		return (1);
	else
		return (0);
}

static int		ft_check_limit_x(t_piece *add, int limit)/*verifie si la piece ne depasse pas la limite x */
{
	int		lmtbit;

	lmtbit = ft_pow(2, 31 - limit);// limit non inclus, barriere exterieure en binaire.
	if ((add->tab[0] & lmtbit || add->tab[1] & lmtbit || add->tab[2] & lmtbit || add->tab[3] & lmtbit))
		return (1);
	return (0);
} //besoin de placer la piece en haut a gauche pour lutiliser

static int		ft_check_limit_y(t_piece *add, int limit)/* Verifie si la piece ne depasse pas la limite Y .*/
{
	if ((add->shift_y + add->size >= limit))
		return (1);
	return (0);
}
t_piece		*ft_search_binary_slot(size_t *binary_map, t_piece *add, int pass, int limit)
{
	//nombre dedecalage effectues de la piece vers x.
 /*add->size of piece*/
	while (add->tab[add->size] & 4294967295)/*find height of add*/
		add->size += 1;
	if (pass > 0)
	{
		add->tab[0] >>= 1;
		add->tab[1] >>= 1;
		add->tab[2] >>= 1;
		add->tab[3] >>= 1;
		add->shift_x += 1;
		pass = 0;
	}
	while (ft_check_binary_mask(binary_map, add)// 
		|| ft_check_limit_x(add, limit)
		|| ft_check_limit_y(add, limit))
	{
		if (ft_check_limit_x(add, limit))
		{
			add->tab[0] <<= add->shift_x;// fonction decalage
			add->tab[1] <<= add->shift_x;
			add->tab[2] <<= add->shift_x;
			add->tab[3] <<= add->shift_x;
			add->shift_y += 1;
			add->shift_x = 0;
			if (ft_check_limit_y(add, limit))
				return (0);
		}
		// voir pour faire un test d' int utile de la piece au debut pour utiliser juste 
		// les int utile, exemple avec un carre en haut a gauche, juste les 2 premiers int.
		else
		{
			add->tab[0] >>= 1;// fonction decalage
			add->tab[1] >>= 1;
			add->tab[2] >>= 1;
			add->tab[3] >>= 1;
			add->shift_x += 1;
		}
	}
	return (add);
}
