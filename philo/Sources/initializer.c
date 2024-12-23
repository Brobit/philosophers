/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:06:16 by almarico          #+#    #+#             */
/*   Updated: 2024/11/01 13:21:42 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	init_param(t_info *info, int argc, char **argv)
{
	info->param = malloc(sizeof(t_param));
	if (!info->param)
		return (FAIL);
	info->param->nb_of_philo = ft_atoll(argv[1]);
	info->param->time_to_die = ft_atoll(argv[2]);
	info->param->time_to_eat = ft_atoll(argv[3]);
	info->param->time_to_sleep = ft_atoll(argv[4]);
	info->param->time_to_think = 1;
	if (argc == 6)
		info->param->nb_of_meal = ft_atoll(argv[5]);
	else
		info->param->nb_of_meal = -1;
	info->param->nb_of_philo_who_finish = 0;
	info->param->start_time_of_simu = get_time_in_ms();
	info->param->is_someone_dead = FALSE;
	pthread_mutex_init(&info->param->display, NULL);
	return (SUCCESS);
}

static void	fill_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->param->nb_of_philo)
	{
		info->philo[i]->id = i + 1;
		info->philo[i]->nb_meal_eat = 0;
		info->philo[i]->time_of_last_meal_in_ms = get_time_in_ms();
		info->philo[i]->left_fork = NULL;
		pthread_mutex_init(&info->philo[i]->right_fork, NULL);
		if (i == info->param->nb_of_philo - 1)
			info->philo[i]->left_fork = &info->philo[0]->right_fork;
		else
			info->philo[i]->left_fork = &info->philo[i + 1]->right_fork;
		info->philo[i]->param = info->param;
		i++;
	}
}

int	init_philo(t_info *info)
{
	int	i;

	info->philo = malloc((info->param->nb_of_philo + 1) * sizeof(t_philo *));
	if (!info->philo)
		return (FAIL);
	info->philo[info->param->nb_of_philo] = NULL;
	i = 0;
	while (i < info->param->nb_of_philo)
	{
		info->philo[i] = malloc(sizeof(t_philo));
		if (!info->philo[i])
			return (FAIL);
		i++;
	}
	fill_philo(info);
	return (SUCCESS);
}
