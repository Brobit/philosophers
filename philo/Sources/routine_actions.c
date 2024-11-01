/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:27:09 by almarico          #+#    #+#             */
/*   Updated: 2024/11/01 13:22:03 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

static void	fork_taking(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		display_fork(philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->right_fork);
		display_fork(philo);
	}
}

void	philo_eating(t_philo *philo)
{
	long	time_to_wait;

	if ((get_time_in_ms() - philo->time_of_last_meal_in_ms) \
		>= philo->param->time_to_die && philo->param->is_someone_dead == FALSE)
	{
		philo->param->is_someone_dead = TRUE;
		display_death(philo);
	}
	if (philo->param->is_someone_dead == FALSE)
	{
		fork_taking(philo);
		display_eating(philo);
		time_to_wait = philo->param->time_to_eat * 1000;
		philo->nb_meal_eat++;
		philo->time_of_last_meal_in_ms = get_time_in_ms();
		usleep(time_to_wait);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	philo_sleeping(t_philo *philo)
{
	long	sleep_phase;

	if (end_of_simulation(philo->param) == FALSE)
	{
		sleep_phase = philo->param->time_to_sleep * 1000;
		display_sleeping(philo);
		usleep(sleep_phase);
	}
}

void	philo_thinking(t_philo *philo)
{
	long	thinking_phase;

	if (end_of_simulation(philo->param) == FALSE)
	{
		thinking_phase = philo->param->time_to_think * 1000;
		display_thinking(philo);
		usleep(thinking_phase);
	}
}
