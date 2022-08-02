/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:13:50 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 14:00:33 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_arg_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	args_validation(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_arg_valid(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (number < 0 && sign < 0)
		return (0);
	else if (number < 0)
		return (-1);
	return (number * sign);
}

int	info_init(int argc, char **argv, t_info **info)
{
	if (!args_validation(argc, argv))
		return (0);
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return (0);
	(*info)->num_of_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	if ((*info)->num_of_philo < 1 || (*info)->time_to_die < 0
		|| (*info)->time_to_eat < 0 || (*info)->time_to_sleep < 0)
		return (0);
	(*info)->num_of_meals = -1;
	if (argc == 6)
	{
		(*info)->num_of_meals = ft_atoi(argv[5]);
		if ((*info)->num_of_meals < 0)
			return (0);
	}
	(*info)->stop_flag = 0;
	return (1);
}
