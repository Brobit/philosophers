/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:37:01 by almarico          #+#    #+#             */
/*   Updated: 2024/11/01 13:21:34 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// # include <bits/pthreadtypes.h>
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
# define ERR_INIT			"An error occur while initialize the structure"

# define RED				"\033[0;31m"
# define GREEN				"\033[0;32m"
# define YELLOW				"\033[0;33m"
# define BLUE				"\033[0;34m"
# define PURPLE				"\033[0;35m"
# define CYAN				"\033[0;36m"
# define RESET				"\033[0m"

typedef long long	t_ll;

typedef struct s_param
{
	int								nb_of_philo;
	int								time_to_die;
	int								time_to_eat;
	int								time_to_sleep;
	int								time_to_think;
	int								nb_of_meal;
	_Atomic int						nb_of_philo_who_finish;
	long							start_time_of_simu;
	_Atomic int						is_someone_dead;
	pthread_mutex_t					display;
}				t_param;

typedef struct s_philo
{
	int								id;
	_Atomic int						nb_meal_eat;
	_Atomic long long				time_of_last_meal_in_ms;
	pthread_mutex_t					right_fork;
	pthread_mutex_t					*left_fork;
	t_param							*param;
	pthread_t						thread_philo;
}				t_philo;

typedef struct s_info
{
	t_param							*param;
	t_philo							**philo;
}				t_info;

/* ft_atoll.c */
t_ll						ft_atoll(const char *string);

/* writing.c */

void						write_program_prompt(void);
void						error(char *str);

/* arg_checker.c */

int							check_args(char *arg);

/* initilizer.c */

int							init_param(t_info *info, int argc, char **argv);
int							init_philo(t_info *info);

/* free_structure.c */

void						free_structure(t_info *info);

/* simulation_entry.c */

void						simulation_entry(t_info *info);

/* time.c */

long						get_time_in_ms(void);

/* routine.c */

void						*start_routine(void	*arg);

/* simulation_checking.c */

int							end_of_simulation(t_param *param);
void						check_meal_nb(t_info *info);
void						check_death(t_info *info);

/* routine_actions.c */

void						philo_eating(t_philo *philo);
void						philo_sleeping(t_philo *philo);
void						philo_thinking(t_philo *philo);

/* one_philo_case.c */

void						simu_one_philo(t_philo *philo);

/* display_message.c */

void						display_fork(t_philo *philo);
void						display_eating(t_philo *philo);
void						display_sleeping(t_philo *philo);
void						display_thinking(t_philo *philo);
void						display_death(t_philo *philo);

#endif // !PHILOSOPHERS_H
