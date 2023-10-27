/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:56:58 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 22:40:21 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A SUPPRIMER */
/*void	print_list(t_li *list)
{
	ft_printf("print list:\n");
	while (list)
	{
		ft_printf("%d\n", list->nbr);
		list = list->next;
	}
}*/

void	reverse_rotate_a(t_li **list, int both)
{
	t_li	*last_node;
	t_li	*before_last;
	t_li	*cpy;

	last_node = *list;
	cpy = *list;
	while (last_node->next)
	{
		before_last = last_node;
		last_node = last_node->next;
	}
	before_last->next = NULL;
	last_node->next = cpy;
	last_node->previous = NULL;
	*list = last_node;
	if (both == 0)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_li **list, int both)
{
	t_li	*last_node;
	t_li	*before_last;
	t_li	*cpy;

	last_node = *list;
	cpy = *list;
	while (last_node->next)
	{
		before_last = last_node;
		last_node = last_node->next;
	}
	before_last->next = NULL;
	last_node->next = cpy;
	last_node->previous = NULL;
	*list = last_node;
	if (both == 0)
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_li **list_a, t_li **list_b)
{
	reverse_rotate_a(list_a, 1);
	reverse_rotate_b(list_b, 1);
	ft_printf("rrr\n");
}
