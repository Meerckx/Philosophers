/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:23:04 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 14:36:05 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	err_mutex_clear(t_info *info, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	return (0);
}

void	mem_clear(t_philo **philo)
{
	err_mutex_clear((*philo)->info, (*philo)->info->num_of_philo);
	free((*philo)->info->forks);
	(*philo)->info->forks = NULL;
	free((*philo)->info);
	(*philo)->info = NULL;
	free((*philo));
	(*philo) = NULL;
}
