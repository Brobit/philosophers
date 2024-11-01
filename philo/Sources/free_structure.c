/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:31:51 by almarico          #+#    #+#             */
/*   Updated: 2024/11/01 13:22:35 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	free_param(t_info *info)
{
	pthread_mutex_destroy(&info->param->display);
	free(info->param);
	info->param = NULL;
}

void	free_philo(t_info *info)
{
	int	i;
	int	philo_nb;

	i = 0;
	philo_nb = info->param->nb_of_philo;
	while (i < philo_nb)
	{
		pthread_mutex_destroy(&info->philo[i]->right_fork);
		free(info->philo[i]);
		info->philo[i] = NULL;
		i++;
	}
	free(info->philo);
	info->philo = NULL;
}

void	free_structure(t_info *info)
{
	free_philo(info);
	free_param(info);
	info = NULL;
}
