/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:36:47 by csil              #+#    #+#             */
/*   Updated: 2023/10/25 00:11:53 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return the biggest number in the linked list */

int	biggest_nbr_list(t_li *list)
{
	int	max;

	if (!list)
		return (0);
	max = list->nbr;
	while (list)
	{
		if (list->nbr > max)
			max = list->nbr;
		list = list->next;
	}
	return (max);
}

/*
	Tu parcours toutes les nodes avec un index vide
	Tu récupère la première node qui a du content
	(Sinon return)
	Et tu la compare aux prochaines
	Si min == la valeur pointée -> lui attribuer l'index
	Sinon se positionner sur la prochaine
*/

int	smaller_nbr_list(t_li *list, int number)
{
	while (list)
	{
		if (list->index)
			list = list->next;
		else if (list->nbr < number)
			return (0);
		else
			list = list->next;
	}
	return (1);
}

/* Return the len of the linked list */

int	lst_len(t_li *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/* Assign the index from the min to the max */

void	assign_index(t_li **list)
{
	int		len;
	int		i;
	t_li	*tmp;
	t_li	*start;

	if (!list)
		return ;
	len = lst_len(*list);
	i = 1;
	tmp = *list;
	start = *list;
	while (i <= len && tmp)
	{
		if (!tmp->index && smaller_nbr_list(*list, tmp->nbr) == 1)
		{
			tmp->index = i;
			i++;
			tmp = start;
		}
		else
			tmp = tmp->next;
	}
}

/* 
	Dans le main:
	Init la struct bage en NULL (cf git Arnaud)
	La faire passer par les cas d'erreur / create list
	Assign les previous
	Assign les index
	Finir par print tous les index
*/

/* A SUPPRIMER */
/*void	print_index(t_li *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_printf ("index: %d", list->index);
		ft_printf (" | nbr: %d\n", list->nbr);
		list = list->next;
	}
}*/
