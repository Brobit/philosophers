/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:39:47 by almarico          #+#    #+#             */
/*   Updated: 2024/10/27 17:25:59 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (argc < 5 || argc > 6)
		return (write_program_prompt(), FAIL);
	i = 1;
	while (i < argc)
	{
		if (check_args(argv[i]) == FAIL)
			return (error(ERR_ARG), FAIL);
		i++;
	}
	if (init_param(&info, argc, argv) == FAIL || init_philo(&info) == FAIL)
		return (error(ERR_INIT), FAIL);
	simulation_entry(&info);
	free_structure(&info);
	return (SUCCESS);
}
