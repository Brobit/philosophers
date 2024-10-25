/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:16:20 by almarico          #+#    #+#             */
/*   Updated: 2024/10/25 13:43:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	simulation_entry(t_info *info)
{
	int	i;

	info->param->start_time_of_simu = get_time_in_ms();
	i = -1;
	while (++i < info->param->nb_of_philo)
		pthread_create(&info->philo[i]->thread_philo, NULL, \
				start_routine, info->philo[i]);
	while (/*simulation doesn't end*/)
	{
		check_meal_nb(info);
		check_death(info);
		usleep(1000);
	}
	// join / detach all the threads
}