/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_previous_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:33:45 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 00:12:37 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* 
	Assign to each nodes of the linked list
	the previous one in the place made for:
	name_list->previous
*/

void	assign_previous_to_node(t_li **list)
{
	int		i;
	t_li	*last;
	t_li	*tmp;

	i = 0;
	last = NULL;
	if (!*list)
		return ;
	tmp = (*list);
	while (tmp)
	{
		if (i == 0)
			tmp->previous = NULL;
		if (i != 0)
			tmp->previous = last;
		last = tmp;
		tmp = tmp->next;
		i++;
	}
	return ;
}

/* A SUPPRIMER */
/*void	print_previous(t_li *li)
{
	if (li == NULL)
	{
		printf ("Alors evidement ...\n");
	}
	while (li)
	{
		if (li->previous)
		{
			ft_printf ("%d\n", li->previous->nbr);
		}
		else
		{
			printf ("bouloulou c'est NULL :)\n");
		}
		li = li->next;
	}
}*/
