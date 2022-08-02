/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:18:57 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 14:21:12 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	mutex_init(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print, NULL))
		return (0);
	info->forks = (pthread_mutex_t *)malloc(info->num_of_philo
			* sizeof(pthread_mutex_t));
	if (!info->forks)
		return (err_mutex_clear(info, 0));
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (err_mutex_clear(info, i));
		i++;
	}
	return (1);
}

static void	current_philo_init(t_philo *philo, int i, t_info *info,
								pthread_mutex_t *forks)
{
	philo->number = i + 1;
	philo->meals_counter = 0;
	philo->last_meal = 0;
	philo->info = info;
	if (i == 0)
	{
		philo->left_fork = &forks[info->num_of_philo - 1];
		philo->right_fork = &forks[i];
	}
	else
	{
		philo->left_fork = &forks[i - 1];
		philo->right_fork = &forks[i];
	}
}

int	philosophers_init(int argc, char **argv, t_philo **philo)
{
	t_info	*info;
	int		i;

	if (!info_init(argc, argv, &info))
		return (0);
	if (!mutex_init(info))
		return (0);
	(*philo) = (t_philo *)malloc(info->num_of_philo * sizeof(t_philo));
	if (!(*philo))
		return (err_mutex_clear(info, info->num_of_philo));
	i = 0;
	while (i < info->num_of_philo)
	{
		current_philo_init(&(*philo)[i], i, info, info->forks);
		i++;
	}
	return (1);
}
