/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:42:56 by bmohamme          #+#    #+#             */
/*   Updated: 2021/10/04 10:50:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		t;
	int				name;
	int				eat_count;
	unsigned long	last_eat;
	int				left;
	int				right;
	struct s_param	*param;
}		t_philo;

typedef struct s_param
{
	pthread_t		dead;
	int				philo_num;
	int				time_live;
	int				eat;
	int				sleep;
	int				eat_num;
	unsigned long	time_start;
	t_philo			*tPhilo;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_sms;
}		t_param;

//libft_func_0
int				ft_isdigit(int c);
int				ft_atoi(const char *s);

//secondary_func_0
void			error_programm(int i);
unsigned long	get_time(void);
void			sms(t_philo *philo, char *str);
void			lock_mutex(t_philo *philo);
void			unlock_mutex(t_philo *philo);

//secondary_func_1
void			my_sleep(unsigned long time);
void			*control_dead(void *param);
void			destroy(t_param *param);

//parser
void			parser(char **argv, t_param *param);
void			init_philo(t_param *param);
void			create_pthread(t_param *param);
void			*start_routine(void *a);

#endif
