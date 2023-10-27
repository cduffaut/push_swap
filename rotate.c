/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:58:40 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 20:20:13 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_li	*ptr_last_node(t_li *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	rotate_a(t_li **list, int both)
{
	t_li	*tmp;
	t_li	*cpy;
	t_li	*reboot;

	tmp = ptr_last_node(*list);
	cpy = (*list);
	cpy->next->previous = NULL;
	reboot = cpy->next;
	cpy->next = NULL;
	tmp->next = cpy;
	cpy->previous = tmp;
	*list = reboot;
	if (both == 0)
		ft_printf("ra\n");
}

void	rotate_b(t_li **list, int both)
{
	t_li	*tmp;
	t_li	*cpy;

	tmp = ptr_last_node(*list);
	cpy = (*list);
	cpy->next->previous = NULL;
	cpy->next = NULL;
	tmp->next = cpy;
	cpy->previous = tmp;
	if (both == 0)
		ft_printf("rb\n");
}

void	rotate_both(t_li **list_a, t_li **list_b)
{
	rotate_a(list_a, 1);
	rotate_b(list_b, 1);
	ft_printf("rr\n");
}
