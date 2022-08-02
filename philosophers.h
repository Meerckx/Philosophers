/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:52:06 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 14:33:25 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	int				stop_flag;
	long long int	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_t		death_checker;
}				t_info;

typedef struct s_philo
{
	int				number;
	int				meals_counter;
	long long int	last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_info			*info;
}				t_philo;

int				philosophers_init(int argc, char **argv, t_philo **philo);
int				info_init(int argc, char **argv, t_info **info);
int				start_dinner(t_philo *philo);
long long int	get_time(void);
void			print_message(t_philo *philo, char *str);
void			ft_sleep(long long int time, t_info *info);
void			mem_clear(t_philo **philo);
int				err_mutex_clear(t_info *info, int num);

#endif