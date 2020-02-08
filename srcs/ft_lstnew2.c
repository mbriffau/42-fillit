/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:39:33 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/25 01:13:41 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*ft_lstnew2(size_t *t, char c)
{
	t_piece *new;
	int		i;

	i = 0;
	new = NULL;
	new = (t_piece*)malloc(sizeof(t_piece));
	if (!new)
		return (NULL);
	new->letter = c;
	new->next = NULL;
	new->shift_x = 0;
	new->shift_y = 0;
	new->size = 0;
	if (!(new->chartab = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	new->chartab[4] = 0;
	while (i < 4)
	{
		if (!(new->chartab[i] = (char*)malloc(sizeof(char) * 5)))
			return (0);
		new->chartab[i][4] = '\0';
		new->tab[i] = t[i];
		i++;
	}
	return (new);
}
