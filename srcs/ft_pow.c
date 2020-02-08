/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:49:02 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/04 18:43:06 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_pow(size_t n, int power)
{
	size_t		exp;

	if (power == 0)
		return (1);
	exp = n;
	while (1 < power--)
	{
		n *= exp;
	}
	return (n);
}
