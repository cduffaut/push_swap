/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:21:40 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 21:53:11 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_li **list, int both)
{
	t_li	*node1;
	t_li	*node2;

	node1 = (*list);
	node2 = (*list)->next;
	node1->next = node2->next;
	node1->previous = node2;
	node2->previous = NULL;
	node2->next = node1;
	*list = node2;
	if (both == 0)
		ft_printf ("sa\n");
}

void	swap_b(t_li **list, int both)
{
	t_li	*node1;
	t_li	*node2;

	node1 = (*list);
	node2 = (*list)->next;
	node1->next = node2->next;
	node1->previous = node2;
	node2->previous = NULL;
	node2->next = node1;
	*list = node2;
	if (both == 0)
		ft_printf ("sb\n");
}

void	swap_both(t_li **list_a, t_li **list_b)
{
	swap_a(list_a, 1);
	swap_b(list_b, 1);
	ft_printf("ss\n");
}
