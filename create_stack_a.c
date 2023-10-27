/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:24:58 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 16:28:50 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A SUPPRIMER */
/*void	print_li(t_li *li)
{
	while (li)
	{
		ft_printf ("%d\n", li->nbr);
		li = li->next;
	}
}*/

void	free_list(t_li **li)
{
	t_li	*tmp;
	t_li	*cpy;

	if (!li)
		return ;
	tmp = NULL;
	cpy = *li;
	while (cpy)
	{
		tmp = cpy->next;
		free(cpy);
		cpy = NULL;
		cpy = tmp;
	}
	*li = NULL;
}

void	add_li(t_li **lst, t_li *new)
{
	t_li	*tmp;

	if (!new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	tmp = (*lst);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return ;
}

t_li	*new_node(int nbr)
{
	t_li	*new;

	new = malloc(sizeof(t_li));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->nbr = nbr;
	return (new);
}

/* To move alone in another file + declare it in the header */
t_li	*create_li(char **tab)
{
	int		i;
	int		nbr;
	t_li	*li;
	t_li	*new;

	li = NULL;
	new = NULL;
	i = 0;
	while (tab[i])
	{
		nbr = ft_atoi(tab[i]);
		new = new_node(nbr);
		add_li(&li, new);
		if (!li || !new)
		{
			free_list(&li);
			return (NULL);
		}
		i++;
	}
	return (li);
}

t_li	*create_li_args(int ac, char **tab)
{
	int		i;
	int		nbr;
	t_li	*li;
	t_li	*new;

	li = NULL;
	new = NULL;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(tab[i]);
		new = new_node(nbr);
		add_li(&li, new);
		if (!li || !new)
		{
			free_list(&li);
			return (NULL);
		}
		i++;
	}
	return (li);
}
