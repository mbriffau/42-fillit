/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:17 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/02/06 18:17:48 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "fillit.h"
# include <fcntl.h>
# include <unistd.h>
# include "stdlib.h"

typedef struct		s_piece
{
	size_t			tab[4];
	char			letter;
	short			shift_y;
	short			shift_x;
	short			size;
	char			**chartab;
	struct s_piece	*next;
}					t_piece;

char				**ft_read_and_clean(char **argv, int *i);
int					*ft_is_valid(char *s);
size_t				*ft_atoui_piece(int *t);
size_t				ft_pow(size_t n, int power);
t_piece				*ft_add_piece_to_list(size_t *tab, t_piece *first);
t_piece				*ft_lstnew2(size_t *tab, char c);
t_piece				*ft_lstadd2(t_piece *first, t_piece *nnew);
size_t				*search_slot(size_t *area, size_t *add);
char				**ft_itoa_piece(t_piece *piece);
size_t				ft_itoa_piece_limit(size_t *t, size_t nb_line);
t_piece				*ft_tpiece_to_char(t_piece *piece);
t_piece				*ft_s_bslot(size_t *binary_map, t_piece *add, int limit);
int					ft_sqrt_sup(int nb);
char				**ft_add_char(char **map_char, t_piece *add);
char				**ft_solver(t_piece *alst, int nb_piece);
t_piece				*ft_lstcopy(t_piece *piece);
t_piece				*ft_binary_tool(t_piece *piece, int n);
char				**ft_post_cleaner(char **map);
size_t				*ft_alloc_binary_map(size_t *binary_map);
void				ft_error(void);
void				*ft_memalloc(size_t size);
void				ft_putstr(char *str);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
char				**ft_double_memalloc(size_t strings, size_t stringsizes);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);

#endif
