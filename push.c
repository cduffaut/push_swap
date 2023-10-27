/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:53:20 by csil              #+#    #+#             */
/*   Updated: 2023/10/26 09:33:13 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_li **list_a, t_li **list_b)
{
	t_li	*next_list_b;

	next_list_b = NULL;
	if (list_b)
	{
		if ((*list_b)->next)
		{
			next_list_b = (*list_b)->next;
			next_list_b->previous = NULL;
		}
		(*list_b)->next = (*list_a);
		if ((*list_a) != NULL)
			(*list_a)->previous = (*list_b);
		(*list_a) = (*list_b);
		(*list_b) = next_list_b;
	}
	ft_printf("pa\n");
}

void	push_b(t_li **list_a, t_li **list_b)
{
	t_li	*next_list_a;

	next_list_a = NULL;
	if (list_a)
	{
		if ((*list_a)->next)
		{
			next_list_a = (*list_a)->next;
			next_list_a->previous = NULL;
		}
		(*list_a)->next = (*list_b);
		if ((*list_b) != NULL)
			(*list_b)->previous = (*list_a);
		(*list_b) = (*list_a);
		(*list_a) = next_list_a;
	}
	ft_printf("pb\n");
}
