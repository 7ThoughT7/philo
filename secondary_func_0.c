/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_func_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:16:07 by bmohamme          #+#    #+#             */
/*   Updated: 2021/10/04 10:53:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_programm(int i)
{
	if (i == 1)
		write(1, "Error malloc\n", 13);
	if (i == 2)
		write(1, "Error time\n", 11);
	if (i == 3)
		write(1, "Invalid arguments\n", 18);
	if (i == 4)
		write(1, "Error mutex_init\n", 17);
	if (i == 5)
		write(1, "Error mutex_lock\n", 17);
	if (i == 6)
		write(1, "Error mutex_lsms\n", 17);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		error_programm(2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sms(t_philo *philo, char *str)
{
	if (pthread_mutex_lock(&philo->param->mutex_sms))
		error_programm(6);
	printf("time (%lu) - philo (%d) : %s\n",
		(get_time() - philo->param->time_start), philo->name, str);
	if (pthread_mutex_unlock(&philo->param->mutex_sms))
		error_programm(6);
	return ;
}

void	lock_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->mutex[philo->left]);
	sms(philo, "lock a left fork");
	pthread_mutex_lock(&philo->param->mutex[philo->right]);
	sms(philo, "lock a right fork");
}

void	unlock_mutex(t_philo *philo)
{
	pthread_mutex_unlock(&philo->param->mutex[philo->left]);
	pthread_mutex_unlock(&philo->param->mutex[philo->right]);
}
