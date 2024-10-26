/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_checking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:40:00 by almarico          #+#    #+#             */
/*   Updated: 2024/10/26 15:44:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	end_of_simulation(t_param *param)
{
	if (param->is_someone_dead == TRUE
		|| param->nb_of_philo_who_finish == param->nb_of_philo)
		return (TRUE);
	return (FALSE);
}

void	check_meal_nb(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->param->nb_of_philo)
	{
		if (info->philo[i]->nb_meal_eat >= info->param->nb_of_meal)
			info->param->nb_of_philo_who_finish++;
		i++;
	}
}

void	check_death(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->param->nb_of_philo)
	{
		if ((get_time_in_ms() - info->philo[i]->time_of_last_meal_in_ms) \
			> info->param->time_to_die)
			info->param->is_someone_dead = TRUE;
		i++;
	}
}
