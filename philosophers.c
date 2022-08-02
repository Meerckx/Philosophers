/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:48:05 by meerckx           #+#    #+#             */
/*   Updated: 2022/06/07 14:33:20 by meerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (!philosophers_init(argc, argv, &philo))
	{
		printf("argc = %d\nInitialization error.\n", argc);
		return (1);
	}
	if (!start_dinner(philo))
		printf("Threads error.\n");
	mem_clear(&philo);
	return (0);
}
