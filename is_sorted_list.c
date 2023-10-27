/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:51:00 by csil              #+#    #+#             */
/*   Updated: 2023/10/26 14:46:42 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return 1 is list is sorted, 0 if not */
int	check_sorted_list(t_bag *stock)
{
	t_li	*tmp;
	t_li	*before;

	tmp = stock->stack_a;
	if (!stock->stack_a)
		return (1);
	while (tmp->next)
	{
		before = tmp;
		if (before->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
