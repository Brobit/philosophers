/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:28:59 by almarico          #+#    #+#             */
/*   Updated: 2024/10/26 15:56:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	simu_one_philo(t_philo *philo)
{
	long	wait_until_dead;

	philo->time_of_last_meal_in_ms = get_time_in_ms();
	wait_until_dead = philo->param->time_to_die * 1000;
	usleep(wait_until_dead);
}
