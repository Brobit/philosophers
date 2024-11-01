/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:20:30 by almarico          #+#    #+#             */
/*   Updated: 2024/11/01 15:07:46 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	display_fork(t_philo *philo)
{
	if (philo->param->is_someone_dead == FALSE)
	{
		pthread_mutex_lock(&philo->param->display);
		printf("%s", GREEN);
		printf("%ld : philo %d has taken a fork\n", \
		get_time_in_ms() - philo->param->start_time_of_simu, philo->id);
		printf("%ld : philo %d has taken a fork\n", \
		get_time_in_ms() - philo->param->start_time_of_simu, philo->id);
		printf("%s", RESET);
		pthread_mutex_unlock(&philo->param->display);
	}
}

void	display_eating(t_philo *philo)
{
	if (philo->param->is_someone_dead == FALSE)
	{
		pthread_mutex_lock(&philo->param->display);
		printf("%s", YELLOW);
		printf("%ld : philo %d is eating\n", \
		get_time_in_ms() - philo->param->start_time_of_simu, philo->id);
		printf("%s", RESET);
		pthread_mutex_unlock(&philo->param->display);
	}
}

void	display_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->display);
	printf("%s", CYAN);
	printf("%ld : philo %d is sleeping\n", \
		get_time_in_ms() - philo->param->start_time_of_simu, philo->id);
	printf("%s", RESET);
	pthread_mutex_unlock(&philo->param->display);
}

void	display_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->display);
	printf("%s", PURPLE);
	printf("%ld : philo %d is thinking\n", \
		get_time_in_ms() - philo->param->start_time_of_simu, philo->id);
	printf("%s", RESET);
	pthread_mutex_unlock(&philo->param->display);
}

void	display_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->display);
	printf("%s", RED);
	printf("%ld : philo %d died\n", \
		get_time_in_ms() - philo->param->start_time_of_simu, philo->id);
	printf("%s", RESET);
	pthread_mutex_unlock(&philo->param->display);
}
