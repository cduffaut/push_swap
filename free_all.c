/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:30 by csil              #+#    #+#             */
/*   Updated: 2023/10/26 15:44:45 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_stock(t_bag *stock, int quit)
{
	if (stock->stack_a)
	{
		free_list(&stock->stack_a);
		stock->stack_a = NULL;
	}
	if (stock->stack_b)
	{
		free_list(&stock->stack_b);
		stock->stack_b = NULL;
	}
	if (quit == 1)
		exit(1);
}
