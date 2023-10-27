/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:23:56 by csil              #+#    #+#             */
/*   Updated: 2023/10/24 20:54:29 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	This part will check all of the numbers in parameters
	if one of thoose "nbrs" do not respect the "rules":
	return: Error

	Two cases:
	1) If it's furnished in severals ARGVS
	2) If it's furnished between quotes ("")
*/

/*
	Check if there is doublons
	1 if yes
	0 if no
*/
int	doublons(int ac, char **av)
{
	int	i;
	int	counter;

	counter = ac;
	while (counter > 0)
	{
		i = ac;
		while (i > 0)
		{
			if (i == counter)
				i--;
			if (i > 0 && ft_strcmp(av[counter], av[i]) == 0)
				return (1);
			i--;
		}
		counter--;
	}
	return (0);
}

/*
	Or len nbr == 10
	check if it does not break the limits
	return 1 if error
	return 0 if it's okay
*/
int	check_limits(int ac, char **av)
{
	int			i;
	int			checker;
	long long	nbr;

	i = 0;
	checker = 0;
	nbr = 0;
	if (av[ac][i] == '-')
		checker = 1;
	if (av[ac][i] == '-' || av[ac][i] == '+')
		i++;
	while (av[ac][i])
	{
		nbr = (nbr * 10) + (av[ac][i] - '0');
		if (checker == 1 && (-nbr < -2147483648))
			return (1);
		else if (checker != 1 && nbr > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

/*
	Check if the number in param is bigger or
	smaller than the limits
	return 1 if it does not fit
	return 0 if everything's ok
*/
int	valid_nbr(int ac, char **av)
{
	int	extra;
	int	i;

	i = 0;
	extra = 0;
	if (av[ac][0] == '-' || av[ac][0] == '+')
		extra = -1;
	while (av[ac][i])
		i++;
	i += extra;
	if (i > 10)
		return (1);
	if (i == 10)
		if (check_limits(ac, av) == 1)
			return (1);
	return (0);
}

/*
	We found a char other than number
	Treatment check if this char is legitimate or not
	if good = return 0
	if error = return 1
*/
int	treatment(int ac, char **av, int i)
{
	if (i == 0 && (av[ac][i] == '+' || av[ac][i] == '-'))
	{
		if (av[ac][i + 1] < '0' || av[ac][i + 1] > '9')
			return (1);
		else
			return (0);
	}
	return (1);
}

/* 
	In case if ARGC > 2
	Function return 1 in case of Error
	Function return 0 if everything's good
*/
int	argv_check(int ac, char **av)
{
	int	i;

	while (ac > 0)
	{
		i = 0;
		if (av[ac][i] < '0' || av[ac][i] > '9')
		{
			if (treatment(ac, av, i) == 1)
				return (1);
			else
				i++;
		}
		while (av[ac][i])
		{
			if (av[ac][i] < '0' || av[ac][i] > '9')
				return (1);
			i++;
		}
		if (valid_nbr(ac, av) == 1)
			return (1);
		if (doublons(ac, av) == 1)
			return (1);
		ac--;
	}
	return (0);
}
