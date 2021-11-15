/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:15:56 by bmohamme          #+#    #+#             */
/*   Updated: 2021/10/04 10:48:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	memory_allocation(t_param *param)
{
	param->tPhilo = malloc(sizeof(t_philo) * param->philo_num);
	param->mutex = malloc(sizeof(pthread_mutex_t) * param->philo_num);
	if (!param->tPhilo || !param->mutex)
		error_programm(1);
}

int	main(int argc, char **argv)
{
	t_param		param;

	if (argc == 5 || argc == 6)
	{
		parser(argv, &param);
		if (param.philo_num < 1 || param.time_live < 1 || param.eat < 1
			|| param.sleep < 1 || param.eat_num == 0)
		{
			error_programm(3);
			return (0);
		}
		memory_allocation(&param);
		init_philo(&param);
		create_pthread(&param);
		free(param.tPhilo);
		free(param.mutex);
	}
	else
		error_programm(3);
	return (0);
}
