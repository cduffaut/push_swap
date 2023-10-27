/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:26:18 by csil              #+#    #+#             */
/*   Updated: 2023/10/26 15:44:16 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

/* ----------- structures ------------ */

typedef struct s_li
{
	int				nbr;
	int				index;
	struct s_li		*previous;
	struct s_li		*next;
}				t_li;

typedef struct s_bag
{
	t_li			*stack_a;
	t_li			*stack_b;
	int				len_total_list;

}				t_bag;

/* ----------- push_swap functions ------------ */

int		argv_check(int ac, char **av);
int		treatment(int ac, char **av, int i);
int		valid_nbr(int ac, char **argv);
int		check_limits(int ac, char **av);
int		doublons(int ac, char **av);
int		quotes_check(char **tab);
int		quotes_doublons(char **tab);
int		ft_strcmp(char	*s1, char *s2);
int		main_check(int ac, char **av);
t_li	*create_li_args(int ac, char **tab);
t_li	*create_li(char **tab);
t_li	*new_node(int nbr);
void	add_li(t_li **lst, t_li *new);
void	free_list(t_li **li);
t_li	*creation_linked_list(int ac, char **av);
void	assign_previous_to_node(t_li **list);
void	assign_index(t_li **list);
int		lst_len(t_li *lst);
int		smaller_nbr_list(t_li *list, int number);
int		biggest_nbr_list(t_li *list);
int		check_sorted_list(t_bag *stock);
void	free_all_stock(t_bag *stock, int quit);

/* ---------- mooving nodes function --------- */

void	push_a(t_li **list_a, t_li **list_b);
void	push_b(t_li **list_a, t_li **list_b);
void	reverse_rotate_a(t_li **list, int both);
void	reverse_rotate_b(t_li **list, int both);
void	reverse_rotate_both(t_li **list_a, t_li **list_b);
t_li	*ptr_last_node(t_li *lst);
void	rotate_a(t_li **list, int both);
void	rotate_b(t_li **list, int both);
void	rotate_both(t_li **list_a, t_li **list_b);
void	swap_a(t_li **list, int both);
void	swap_b(t_li **list, int both);
void	swap_both(t_li **list_a, t_li **list_b);

/* ---------- algo functions --------- */

void	main_less_or_5(t_bag *stock);
void	len_equal_5(t_bag *stock);
void	len_equal_4(t_bag *stock);
void	len_equal_3(t_bag *stock);
void	len_equal_2(t_bag *stock);

#endif
