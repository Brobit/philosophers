/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_checking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:40:00 by almarico          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:30 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"
#include <pthread.h>

int	end_of_simulation(t_param *param)
{
	pthread_mutex_lock(&param->check_end);
	if (param->is_someone_dead == TRUE
		|| param->nb_of_philo_who_finish == param->nb_of_philo)
		return (pthread_mutex_unlock(&param->check_end), TRUE);
	return (pthread_mutex_unlock(&param->check_end), FALSE);
}

void	check_meal_nb(t_info *info)
{
	int	i;

	pthread_mutex_lock(&info->param->check_meal);
	i = 0;
	while (i < info->param->nb_of_philo)
	{
		if (info->philo[i]->nb_meal_eat >= info->param->nb_of_meal
			&& info->param->nb_of_meal != -1)
			info->param->nb_of_philo_who_finish++;
		i++;
	}
	pthread_mutex_unlock(&info->param->check_meal);
}

void	check_death(t_info *info)
{
	int	i;

	pthread_mutex_lock(&info->param->check_death);
	i = 0;
	while (i < info->param->nb_of_philo)
	{
		if ((get_time_in_ms() - info->philo[i]->time_of_last_meal_in_ms) \
			>= info->param->time_to_die)
		{
			info->param->is_someone_dead = TRUE;
			display_death(info->philo[i]);
		}
		i++;
	}
	pthread_mutex_unlock(&info->param->check_death);
}
