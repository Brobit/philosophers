/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:41:16 by almarico          #+#    #+#             */
/*   Updated: 2024/10/25 18:18:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	*start_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg; 
	if (philo->param->nb_of_philo == 1)
		simu_one_philo(philo);
	else
	{
		while (end_of_simulation(philo->param) == FALSE)
		{
			philo_eating(philo);
			philo_sleeping(philo);
			philo_thinking(philo);
		}
	}
	return (NULL);
}
