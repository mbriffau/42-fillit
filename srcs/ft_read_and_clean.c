/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:07:33 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/02/06 20:07:35 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

static void	ft_error_check(char *buffer, int last)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (((i + 1) % 5) == 0)
		{
			if (!(buffer[i] == '\n'))
				ft_error();
		}
		else if (buffer[i] != '.' && buffer[i] != '#')
			ft_error();
		i++;
	}
	if ((last > 0) && (buffer[20] != '\n'))
		ft_error();
}

static char	*ft_clean(char *str, char *buffer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	while (i < 16)
	{
		if (i > 0 && (i % 4) == 0)
			j++;
		str[i] = buffer[i + j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_reader(int fd, char **tab, int *i, int j)
{
	char	buffer[21];

	while (read(fd, buffer, 21) != 0)
	{
		j--;
		tab[*i] = ft_clean(tab[*i], buffer);
		*i = *i + 1;
		ft_error_check(buffer, j);
		ft_bzero(buffer, 21);
	}
	return (tab);
}

char		**ft_read_and_clean(char **argv, int *i)
{
	int		fd;
	char	**tab;
	char	buffer[21];
	int		j;

	j = 0;
	ft_memset(buffer, '\0', 21);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	while (read(fd, buffer, 21) != 0)
	{
		j += ft_strlen(buffer);
		*i = *i + 1;
		ft_bzero(buffer, 21);
	}
	if (j != ((*i * 21) - 1) || (*i > 26))
		ft_error();
	close(fd);
	if (!(tab = (char**)malloc(sizeof(char*) * *i + 1)))
		return (0);
	tab[*i] = 0;
	j = *i;
	*i = 0;
	fd = open(argv[1], O_RDONLY);
	return (tab = ft_reader(fd, tab, i, j));
}
