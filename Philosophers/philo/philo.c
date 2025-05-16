/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopes-c <jlopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:53:49 by jlopes-c          #+#    #+#             */
/*   Updated: 2025/05/16 12:59:59 by jlopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//make routine here

int ate_everything(t_info *data)
{
	int i;
	int food_flag;

	i = 0;
	food_flag = 0;

	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i]->meal_lock); //hmmmm not sure about this whole thing
		if (data->philo[i]->times_ate == data->philo_num_eat)
			food_flag++;
		pthread_mutex_unlock(&data->philo[i]->meal_lock);
		i++;
	}
	if (food_flag == data->philo_num)
		return (1);
	return (0);
}

void *check_death(t_info *data, t_philo *philo)
{
	int i;
	i = 0;

	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i]->meal_lock);
		if ((get_time_in_ms() - data->philo[i]->last_meal) > data->philo_ttd) //hmmmm
			print_current_action(&philo[i], "is dead");
		return (NULL);
	}
	return (NULL);
}


void eat_routine(t_philo *data)
{
	
	pthread_mutex_lock(&data->info->forks[data->fork[0]]);
	print_current_action(data,"has taken a fork");
	pthread_mutex_lock(&data->info->forks[data->fork[1]]);
	print_current_action(data,"has taken a fork");
	
	pthread_mutex_lock(&data->meal_lock);
	print_current_action(data,"is eating");
	data->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&data->meal_lock);

	philo_sleep(data->info->philo_tte);

	pthread_mutex_lock(&data->meal_lock);
	data->times_ate = data->times_ate + 1;
	pthread_mutex_unlock(&data->meal_lock);
	
	pthread_mutex_unlock(&data->info->forks[data->fork[0]]);
	//print_current_action(data,"Releases Fork 1");
	pthread_mutex_unlock(&data->info->forks[data->fork[1]]);
	//print_current_action(data,"Releases Fork 2");
	
	print_current_action(data,"is sleeping");

	philo_sleep(data->info->philo_tts);

	print_current_action(data,"is thinking");
	
}

void *philo_routine(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;

	if (philo->id % 2 == 0)
		philo_sleep(10);
	
	while(philo)
		eat_routine(philo);
	return (NULL);
}

void create_thrd(t_info *data)
{
	int i;
	i = 0;
	
	while( i < data->philo_num)
	{
		pthread_create(&data->philo[i]->thread, NULL, philo_routine, data->philo[i]);
		i++;
	}
}

void end_thrd(t_info *data)
{
	int i;
	i = 0;
	while ( i < data->philo_num)
	{
		pthread_join(data->philo[i]->thread, NULL);
		i++;
	}
}



int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		 exit(1);
	//check_valid_stuff
	t_info *data;
	data = NULL;
	//initiate thread
	init_values(argv,data);
	create_thrd(data);
	end_thrd(data);

	//start simulation

	//end simulation

	return (0);
}