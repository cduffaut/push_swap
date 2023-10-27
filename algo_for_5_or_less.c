/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_5_or_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:43 by csil              #+#    #+#             */
/*   Updated: 2023/10/26 15:58:41 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* A SUPPRIMER */
/*void	print_list(t_li *list)
{
	while (list)
	{
		printf("nbr %d | index %d\n", list->nbr, list->index);
		list = list->next;
	}
}*/

void	len_equal_2(t_bag *stock)
{
	if (stock->stack_a->nbr > stock->stack_a->next->nbr)
		swap_a(&stock->stack_a, 0);
}

void	len_equal_3(t_bag *stock)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stock->stack_a->index;
	n2 = stock->stack_a->next->index;
	n3 = stock->stack_a->next->next->index;
	if ((n1 < n2) && (n2 > n3) && (n3 > n1))
	{
		reverse_rotate_a(&stock->stack_a, 0);
		swap_a(&stock->stack_a, 0);
	}
	else if ((n1 > n2) && (n2 < n3) && (n3 > n1))
		swap_a(&stock->stack_a, 0);
	else if ((n1 < n2) && (n2 > n3) && (n3 < n1))
	{
		reverse_rotate_a(&stock->stack_a, 0);
	}
	if ((n1 > n2) && (n2 > n3) && (n3 < n1))
	{
		swap_a(&stock->stack_a, 0);
		reverse_rotate_a(&stock->stack_a, 0);
	}
	else if ((n1 > n2) && (n2 < n3) && (n3 < n1))
		rotate_a(&stock->stack_a, 0);
}

void	len_equal_4(t_bag *stock)
{
	push_b(&stock->stack_a, &stock->stack_b);
	len_equal_3(stock);
	if (stock->stack_b->nbr < stock->stack_a->nbr)
	{
		push_a(&stock->stack_a, &stock->stack_b);
	}
	else if (stock->stack_b->nbr > stock->stack_a->next->next->nbr)
	{
		push_a(&stock->stack_a, &stock->stack_b);
		rotate_a(&stock->stack_a, 0);
	}	
	else if (stock->stack_b->nbr < stock->stack_a->next->nbr)
	{
		push_a(&stock->stack_a, &stock->stack_b);
		swap_a(&stock->stack_a, 0);
	}
	else if (stock->stack_b->nbr > stock->stack_a->next->nbr)
	{
		reverse_rotate_a(&stock->stack_a, 0);
		push_a(&stock->stack_a, &stock->stack_b);
		rotate_a(&stock->stack_a, 0);
		rotate_a(&stock->stack_a, 0);
	}
}

void	len_equal_5(t_bag *stock)
{
	if (stock->stack_b->nbr < stock->stack_a->next->nbr)
	{
		push_a(&stock->stack_a, &stock->stack_b);
		swap_a(&stock->stack_a, 0);
	}
	else if (stock->stack_b->nbr < stock->stack_a->next->next->nbr)
	{
		rotate_a(&stock->stack_a, 0);
		rotate_a(&stock->stack_a, 0);
		push_a(&stock->stack_a, &stock->stack_b);
		reverse_rotate_a(&stock->stack_a, 0);
		reverse_rotate_a(&stock->stack_a, 0);
	}
	else if (stock->stack_b->nbr < stock->stack_a->next->next->next->nbr)
	{
		reverse_rotate_a(&stock->stack_a, 0);
		push_a(&stock->stack_a, &stock->stack_b);
		rotate_a(&stock->stack_a, 0);
		rotate_a(&stock->stack_a, 0);
	}
	else if (stock->stack_b->nbr > stock->stack_a->next->next->next->nbr)
	{
		push_a(&stock->stack_a, &stock->stack_b);
		rotate_a(&stock->stack_a, 0);
	}
}

void	main_less_or_5(t_bag *stock)
{
	if (stock->len_total_list == 2)
		len_equal_2(stock);
	else if (stock->len_total_list == 3)
		len_equal_3(stock);
	else if (stock->len_total_list == 4)
		len_equal_4(stock);
	else if (stock->len_total_list == 5)
	{
		push_b(&stock->stack_a, &stock->stack_b);
		len_equal_4(stock);
		if (stock->stack_b->nbr < stock->stack_a->nbr)
			push_a(&stock->stack_a, &stock->stack_b);
		else
			len_equal_5(stock);
	}
}
