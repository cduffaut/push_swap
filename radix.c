/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:23:42 by csil              #+#    #+#             */
/*   Updated: 2023/10/26 22:48:19 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_shift(t_bag *stock)
{
	while ((stock->len_total_list >> stock->max_shift) != 0)
	{
		stock->max_shift++;
	}
}

void	radix(t_bag *stock, int shift)
{
	int	len;

	if (shift >= stock->max_shift)
		return ;
	len = 0;
	while (len < stock->len_total_list)
	{
		if ((stock->stack_a->index >> shift) & 1)
			rotate_a(&stock->stack_a, 0);
		else
			push_b(&stock->stack_a, &stock->stack_b);
		len ++;
	}
	while (stock->stack_b)
	{
		push_a(&stock->stack_a, &stock->stack_b);
	}
	radix(stock, shift + 1);
}
