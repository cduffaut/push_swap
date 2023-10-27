/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_create_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:07 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 16:55:53 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_li	*creation_linked_list(int ac, char **av)
{
	t_li	*list;
	char	**tab_elem;

	list = NULL;
	if (av[1][0] == '\0')
		return (NULL);
	else if (ac == 2)
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
	return (list);
}
