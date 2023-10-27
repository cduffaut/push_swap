/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_create_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:07 by csil              #+#    #+#             */
/*   Updated: 2023/10/27 16:20:04 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that recheck that there is no double */
void	check_double_list(t_li *list)
{
	t_li	*tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (tmp->nbr == list->nbr)
			{
				ft_putstr_fd("Error\n", 2);
				free_list(&list);
				exit(1);
			}
			tmp = tmp->next;
		}
		list = list->next;
	}
}

t_li	*creation_linked_list(int ac, char **av)
{
	t_li	*list;
	char	**tab_elem;

	list = NULL;
	if (ac == 2)
	{
		tab_elem = ft_split(av[1], ' ');
		if (!tab_elem)
			return (NULL);
		list = create_li(tab_elem);
		free_split(tab_elem);
	}
	else if (ac > 2)
		list = create_li_args(ac, av);
	if (!list)
	{
		free_list(&list);
		return (NULL);
	}
	check_double_list(list);
	return (list);
}
