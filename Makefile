# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 20:12:50 by mbriffau          #+#    #+#              #
#    Updated: 2018/04/08 00:21:42 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS_PATH = srcs/
OBJ_PATH = obj/

SRCS_NAME = \
			fillitmain  \
			ft_add_char \
			ft_add_piece_to_list \
			ft_alloc_binary_map \
			ft_atoui_piece \
			ft_is_valid \
			ft_lstadd2 \
			ft_lstcopy \
			ft_lstnew2 \
			ft_post_cleaner \
			ft_pow \
			ft_read_and_clean \
			ft_s_bslot \
			ft_solver \
			ft_sqrt_sup \
			ft_tpiece_to_char \
			ft_memset \
			ft_strlen \
			ft_memalloc \
			ft_double_memalloc \
			ft_bzero \
			ft_putstr

SRCS = $(addsuffix .c, $(SRCS_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@echo "$(notdir $<)\033[1m\033[32m compiled.\033[0m"
	@mkdir -p `dirname $@`
	@gcc -c $(FLAGS) $< -o $@

clean:
	-/bin/rm -rf $(OBJ_PATH)
	@echo "All files .o have been \033[1;31mdeleted\033[0m."

fclean: clean
	-/bin/rm -f $(NAME)
	@echo "$(NAME) has been \033[1;31mdeleted\033[0m."

re: fclean all

.PHONY: all, clean, fclean, re