/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:07:03 by bmohamme          #+#    #+#             */
/*   Updated: 2021/10/04 10:45:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *a)
{
	t_philo	*philo;

	philo = (t_philo *)a;
	pthread_detach(philo->t);
	philo->last_eat = philo->param->time_start;
	while (1)
	{
		if (philo->eat_count != 0)
		{
			lock_mutex(philo);
			sms(philo, "eating");
			philo->eat_count--;
			my_sleep(philo->param->eat);
			unlock_mutex(philo);
			philo->last_eat = get_time();
			sms(philo, "sleeping");
			my_sleep(philo->param->sleep);
			sms(philo, "thinking");
		}
		else
			break ;
	}
	return (NULL);
}

void	create_pthread(t_param *param)
{
	int	count;

	count = -1;
	param->time_start = get_time();
	while (++count < param->philo_num)
	{
		if (count % 2 == 0)
			pthread_create(&param->tPhilo[count].t, NULL, &start_routine,
				  &param->tPhilo[count]);
		usleep(30);
	}
	count = -1;
	usleep(30);
	while (++count < param->philo_num)
	{
		if (count % 2 == 1)
			pthread_create(&param->tPhilo[count].t, NULL, &start_routine,
				  &param->tPhilo[count]);
		usleep(30);
	}
	pthread_create(&param->dead, NULL, &control_dead, param);
	pthread_join(param->dead, NULL);
	destroy(param);
}

void	init_philo(t_param *param)
{
	int	count;

	count = -1;
	while (++count < param->philo_num)
	{
		param->tPhilo[count].eat_count = param->eat_num;
		param->tPhilo[count].name = count + 1;
		param->tPhilo[count].param = param;
		if (pthread_mutex_init(&param->mutex[count], NULL) != 0)
			error_programm(4);
		param->tPhilo[count].left = count;
		if (count < param->philo_num - 1)
			param->tPhilo[count].right = (count + 1);
	}
	if (param->philo_num != 1)
		param->tPhilo[--count].right = 0;
	if (param->philo_num == 1)
		param->tPhilo[0].right = 0;
}

void	parser(char **argv, t_param *param)
{
	param->philo_num = ft_atoi(argv[1]);
	param->time_live = ft_atoi(argv[2]);
	param->eat = ft_atoi(argv[3]);
	param->sleep = ft_atoi(argv[4]);
	if (argv[5])
		param->eat_num = ft_atoi(argv[5]);
	else
		param->eat_num = -1;
	if (pthread_mutex_init(&param->mutex_sms, NULL))
		error_programm(4);
}
