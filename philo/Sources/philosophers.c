/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:39:47 by almarico          #+#    #+#             */
/*   Updated: 2024/10/22 11:08:13 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	main(int argc, char **argv)
{
	t_param	param;
	int		i;

	if (argc != 5 || argc != 6)
		return (write_program_prompt(), FAIL);
	i = 1;
	while (i < argc)
	{
		if (check_args(argv[i]) == FAIL)
			return (error(ERR_ARG), FAIL);
		i++;
	}
	return (SUCCESS);
}
