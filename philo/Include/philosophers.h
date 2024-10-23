/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:37:01 by almarico          #+#    #+#             */
/*   Updated: 2024/10/23 14:53:36 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <bits/pthreadtypes.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define SUCCESS			0
# define FAIL				1
# define TRUE				1
# define FALSE				0
# define INT_MIN			-2147483648
# define INT_MAX			2147483647

# define ERR_ARG			"There is an invalid argument"

typedef long long	t_ll;

typedef struct s_param
{
	int								nb_of_philo;
	int								time_to_die;
	int								time_to_eat;
	int								time_to_sleep;
	int								nb_of_meal;
	int								nb_of_philo_who_finish;
	pthread_mutex_t					is_someone_dead;
}				t_param;

typedef struct s_philo
{
	int								id;
	int								nb_meal_eat;
	long long						time_since_last_eat_in_ms;
	pthread_mutex_t					right_fork;
	pthread_mutex_t					left_fork;
	t_param							*param;
	pthread_t						*thread_philo;
}				t_philo;

/* ft_atoll.c */
t_ll						ft_atoll(const char *string);

/* writing.c */

void						write_program_prompt(void);
void						error(char *str);

/* arg_checker.c */

int							check_args(char *arg);

#endif // !PHILOSOPHERS_H
