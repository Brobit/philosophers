/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:20:30 by almarico          #+#    #+#             */
/*   Updated: 2024/10/26 15:52:29 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	display_fork(t_philo *philo)
{
	printf("%ld : philo %d has taken a fork\n", get_time_in_ms(), philo->id);
	printf("%ld : philo %d has taken a fork\n", get_time_in_ms(), philo->id);
}

void	display_eating(t_philo *philo)
{
	printf("%ld : philo %d is eating\n", get_time_in_ms(), philo->id);
}

void	display_sleeping(t_philo *philo)
{
	printf("%ld : philo %d is sleeping\n", get_time_in_ms(), philo->id);
}

void	display_thinking(t_philo *philo)
{
	printf("%ld : philo %d is thinking\n", get_time_in_ms(), philo->id);
}

void	display_death(t_philo *philo)
{
	printf("%ld : philo %d died\n", get_time_in_ms(), philo->id);
}
