/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:30:56 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 13:59:24 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_message(t_philo *philo, char *str)
{
	long long int	cur_time;

	pthread_mutex_lock(&philo->info->print);
	cur_time = get_time();
	if (!philo->info->stop_flag)
		printf("%lld %d %s\n", cur_time - philo->info->start_time,
			philo->number, str);
	pthread_mutex_unlock(&philo->info->print);
}

void	ft_sleep(long long int time, t_info *info)
{
	long long int	tmp;

	tmp = get_time();
	while (!info->stop_flag)
	{
		if (get_time() - tmp >= time)
			break ;
		usleep(500);
	}
}
