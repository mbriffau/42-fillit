/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchslot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:27:03 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/19 01:39:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_add_piece(size_t *area, size_t *add, int decal)/*renvoit la somme de area et de add */
{
	area[decal + 0] += add[0];
	area[decal + 1] += add[1];
	area[decal + 2] += add[2];
	area[decal + 3] += add[3];
	return ((size_t*)area);
}

static int		ft_check_binary_mask(size_t *area, size_t *add, int decal)/*verifie si les deux pieces se chevauchent.*/
{/*fonction verifie c'est OK*/
	if (area[decal + 0] & add[0] || area[decal + 1] & add[1]
	 || area[decal + 2] & add[2] || area[decal + 3] & add[3])
		return (1);
	else
		return (0);
}

static int		ft_check_limit_x(size_t *add, int limit)/*verifie si la piece ne depasse pas la limite x */
{
	int		lmtbit;

	lmtbit = ft_pow(2, 31 - limit);// limit non inclus, barriere exterieure en binaire.
	if ((add[0] & lmtbit || add[1] & lmtbit || add[2] & lmtbit || add[3] & lmtbit))
		return (1);
	return (0);
} //besoin de placer la piece en haut a gauche pour lutiliser

static int		ft_check_limit_y(size_t *add, int limit, int decal)/* Verifie si la piece ne depaase pas la limite Y .*/
{
	int		size; /*size of piece*/

	size = 0;
	while (add[size] & 4294967295)/*find height of add*/
	{
		size++;
	}
	if ((decal + size == limit))
		return (1);
	return (0);
}

size_t		*search_slot(size_t *area, size_t *add) // trouve l'emplacement de la piece add dans area, area peut etre un piece ou la somme de plusiers pieces.
{
	printf("search_slot\n");
	int		limit;/*limite a ne pas depasser*/
	int		decal;/*decalage en Y*/
	int		nbx;//nombre dedecalage effectues de la piece vers x.

	decal = 0;
	limit = 4;
	nbx = 0;
	while (ft_check_binary_mask(area, add, decal)// 
		|| ft_check_limit_x(add, limit)
		|| ft_check_limit_y(add, limit, decal))
	{
		if (ft_check_limit_x(add, limit))
		{
			add[0] <<= nbx;
			add[1] <<= nbx;
			add[2] <<= nbx;
			add[3] <<= nbx;
			decal++;
			nbx = 0;
		}
		if (ft_check_limit_y(add, limit, decal))
		{
			decal = 0;
			limit ++;
		}
		// voir pour faire un test d' int utile de la piece au debut pour utiliser juste 
		// les int utile, exemple avec un carre en haut a gauche, juste les 2 premiers int.
		else
		{
			add[0] >>= 1;// fonction decalage
			add[1] >>= 1;
			add[2] >>= 1;
			add[3] >>= 1;
			nbx++;
		}
	}
	return (ft_add_piece(area, add, decal));
}
