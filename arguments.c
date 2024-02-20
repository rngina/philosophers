/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:46:28 by rtavabil          #+#    #+#             */
/*   Updated: 2024/02/16 16:50:52 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_numerics(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-' ) && (!(*(s + 1) >= '0' && *(s + 1) <= '9')))
		return (1);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (1);
	}
	return (0);
}

long int	ft_atol(char *str)
{
	long int	nb;

	nb = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			write(2, "Parameter can not be negative\n", 31);
			exit(1);
		}
		str++;
	}
	while (47 < *str && *str < 58)
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (nb);
}

static int	check_args(char *argv)
{
	long int	check;

	if (check_numerics(argv))
	{
		write(2, "Enter numeric parameters\n", 26);
		exit(1);
	}
	check = ft_atol(argv);
	if ((check > INT_MAX))
	{
		write(2, "Parameter is not in INT limits\n", 32);
		exit(1);
	}
	return ((int)check);
}

void	set_args(char **argv, t_args *args)
{
	args->number_of_philosophers = check_args(argv[1]);
	args->time_to_die = check_args(argv[2]);
	args->time_to_eat = check_args(argv[3]);
	args->time_to_sleep = check_args(argv[4]);
	if (argv[5])
		args->number_of_times_each_philosopher_must_eat = check_args(argv[5]);
	else
		args->number_of_times_each_philosopher_must_eat = -1;
}
