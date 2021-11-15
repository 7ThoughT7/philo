/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:16:24 by bmohamme          #+#    #+#             */
/*   Updated: 2021/10/04 11:10:16 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int			i;
	long long	n;

	i = 0;
	n = 0;
	if (s[i] == '-')
		return (0);
	while (s[i])
		if (ft_isdigit(s[i++]) != 1)
			return (0);
	i = 0;
	while (s[i])
	{
		n = (n * 10) + (s[i++] - 48);
		if (n < -2147483648)
			return (0);
		if (n > 2147483647)
			return (0);
	}
	return ((int)n);
}
