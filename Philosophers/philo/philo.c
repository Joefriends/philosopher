/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopes-c <jlopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:53:49 by jlopes-c          #+#    #+#             */
/*   Updated: 2025/05/15 15:11:24 by jlopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//make routine here

void eat_routine(t_philo *data)
{
	pthread_mutex_lock(&data->info->forks[data->fork[0]]);
	printf("Owns Fork 1");
	pthread_mutex_lock(&data->info->forks[data->fork[1]]);
	printf("Owns Fork 2");
	
	pthread_mutex_lock(&data->meal_lock);
	printf("Is eating");
	data->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&data->meal_lock);

	philo_sleep(data->info->philo_tte);

	pthread_mutex_lock(&data->meal_lock);
	data->times_ate = data->times_ate + 1;
	pthread_mutex_unlock(&data->meal_lock);
	
	pthread_mutex_unlock(&data->info->forks[data->fork[0]]);
	printf("Releases Fork 1");
	pthread_mutex_unlock(&data->info->forks[data->fork[1]]);
	printf("Releases Fork 2");
	
	printf("Is asleep");

	philo_sleep(data->info->philo_tts);

	printf("Is thinking");
	
}


void *philo_routine(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;
	
	
	
}

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		 exit(1);
	//check_valid_stuff

	//initiate thread

	//start simulation

	//end simulation

	return (0);
}