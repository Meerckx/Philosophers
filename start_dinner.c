/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:19 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 15:12:48 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_eating(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->info->stop_flag)
	{
		print_message(philo, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
		print_message(philo, "is eating");
		philo->last_meal = get_time();
		ft_sleep(philo->info->time_to_eat, philo->info);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		if (!philo->info->stop_flag)
			philo->meals_counter++;
		print_message(philo, "is sleeping");
		ft_sleep(philo->info->time_to_sleep, philo->info);
	}
	return (0);
}

void	*check_philo(void *args)
{
	t_philo	*philo;
	int		i;
	int		eats_count;

	philo = (t_philo *)args;
	while (!philo->info->stop_flag)
	{
		i = -1;
		eats_count = 0;
		while (++i < philo->info->num_of_philo)
		{
			if (get_time() - philo[i].last_meal > philo->info->time_to_die)
			{
				print_message(&philo[i], "died");
				philo->info->stop_flag = 1;
				break ;
			}
			if (philo->info->num_of_meals != -1
				&& philo[i].meals_counter >= philo->info->num_of_meals)
				eats_count++;
		}
		if (eats_count == philo->info->num_of_philo)
			philo->info->stop_flag = 1;
	}
	return (0);
}

int	start_dinner(t_philo *philo)
{
	int	i;

	i = 0;
	philo->info->start_time = get_time();
	while (i < philo->info->num_of_philo)
	{
		philo[i].last_meal = get_time();
		if (pthread_create(&philo[i].thread, NULL, &start_eating, &philo[i]))
			return (0);
		pthread_detach(philo[i].thread);
		usleep(25);
		i++;
	}
	if (pthread_create(&philo->info->death_checker, NULL, &check_philo, philo))
		return (0);
	if (pthread_join(philo->info->death_checker, NULL))
		return (0);
	return (1);
}
