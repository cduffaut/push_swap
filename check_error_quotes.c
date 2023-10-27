/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:42:38 by csil              #+#    #+#             */
/*   Updated: 2023/10/27 09:17:48 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	quotes_doublons(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (j == i)
				j++;
			if (tab[j] && ft_strcmp(tab[i], tab[j]) == 0)
			{
				return (1);
			}
			if (tab[j])
				j++;
		}
		i++;
	}
	return (0);
}

int	quotes_check(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] < '0' || tab[i][j] > '9')
		{
			if (treatment(i, tab, j) == 1)
				return (1);
			else
				j++;
		}
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (1);
			j++;
		}
		if (valid_nbr(i, tab) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	main_check(int ac, char **av)
{
	char	**tab_elem;
	int		check_error;

	check_error = 0;
	if (ac <= 1)
		return (1);
	else if (ac == 2)
	{
		tab_elem = ft_split(av[1], ' ');
		if (!tab_elem)
			return (1);
		check_error += quotes_check(tab_elem);
		check_error += quotes_doublons(tab_elem);
		free_split(tab_elem);
	}
	else if (ac > 2)
	{
		ac -= 1;
		check_error = argv_check(ac, av);
	}
	if (check_error == 1)
		ft_printf("Error\n");
	if (check_error > 0)
		return (1);
	return (0);
}
