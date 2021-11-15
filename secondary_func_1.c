/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_func_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:16:45 by bmohamme          #+#    #+#             */
/*   Updated: 2021/10/03 21:27:01 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(unsigned long time)
{
	unsigned long	i;

	i = get_time() + time;
	usleep((time - 10) * 1000);
	while (get_time() <= i)
		usleep(50);
}

int	check_dead(t_param *param, int count)
{
	unsigned long	dead;

	dead = get_time() - param->tPhilo[count].last_eat;
	if ((int)(dead) > param->time_live)
	{
		pthread_mutex_lock(&param->mutex_sms);
		printf("time (%lu) - Philo %d dead", dead, count + 1);
		return (1);
	}
	return (0);
}

void	*control_dead(void *param)
{
	t_param	*tmp;
	int		count;
	int		sum_eat;

	tmp = (t_param *)param;
	while (1)
	{
		count = 0;
		sum_eat = 0;
		while (count < tmp->philo_num)
		{
			if (check_dead(tmp, count) == 1)
				return (NULL);
			sum_eat += tmp->tPhilo[count++].eat_count;
		}
		if (sum_eat == 0)
		{
			pthread_mutex_lock(&tmp->mutex_sms);
			printf("%s ", "All philo eating");
			return (NULL);
		}
	}
}

void	destroy(t_param *param)
{
	int	count;

	count = 0;
	while (count < param->philo_num)
		pthread_mutex_destroy(&param->mutex[count++]);
	pthread_mutex_destroy(&param->mutex_sms);
}
