/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:16:20 by almarico          #+#    #+#             */
/*   Updated: 2024/11/01 13:33:08 by almarico         ###   ########.fr       */
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
	while (end_of_simulation(info->param) == FALSE)
	{
		check_meal_nb(info);
		check_death(info);
	}
	i = -1;
	while (++i < info->param->nb_of_philo)
		pthread_join(info->philo[i]->thread_philo, NULL);
}
