/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:01:56 by csil              #+#    #+#             */
/*   Updated: 2023/10/27 09:58:18 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A SUPPRIMER */
void	print_list(t_li *list)
{
	ft_printf("list:\n");
	while (list)
	{
		ft_printf("%d | ", list->index);
		ft_printf("%d\n", list->nbr);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_bag	stock;

	stock = (t_bag){};
	if (main_check(argc, argv) == 1)
		return (1);
	stock.stack_a = creation_linked_list(argc, argv);
	stock.stack_b = NULL;
	if (stock.stack_a == NULL)
		free_all_stock(&stock, 1);
	assign_previous_to_node(&stock.stack_a);
	assign_index(&stock.stack_a);
	stock.len_total_list = lst_len(stock.stack_a);
	if (check_sorted_list(&stock) == 1)
	{
		free_all_stock(&stock, 0);
		return (0);
	}
	else if (stock.len_total_list <= 5)
		main_less_or_5(&stock);
	free_all_stock(&stock, 0);
	return (0);
}
