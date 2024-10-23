/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:02:53 by almarico          #+#    #+#             */
/*   Updated: 2024/10/22 11:32:34 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	check_args(char *arg)
{
	long	nb;

	if (!arg || *arg == '0' || *arg == '\0')
		return (FAIL);
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (FAIL);
		nb = nb * 10 + (*arg - '0');
		if (nb > INT_MAX)
			return (FAIL);
		arg++;
	}
	return (SUCCESS);
}
