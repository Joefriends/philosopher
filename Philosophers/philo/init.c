/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopes-c <jlopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:53:45 by jlopes-c          #+#    #+#             */
/*   Updated: 2025/05/13 12:53:46 by jlopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


pthread_mutex_t *initialize_forks(t_info *data)
{
	int i;
	pthread_mutex_t *forks; // think of forks like mutex locks
	i = 0;

	forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!forks)
		return (NULL); // make error stat later 
	
	while (i < data->philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		
		//check for error
		printf("Fork %d created\n", i);

		i++;
	}
	return (forks);

}

void *initialize_philosophers(t_philo *data)
{


}         

void *init_values(char **argv, t_info *data)
{
	

	data->philo_num = ft_atoi(argv[1]);
	data->philo_ttd = ft_atoi(argv[2]);
	data->philo_tte = ft_atoi(argv[3]);
	data->philo_tts = ft_atoi(argv[4]);

	data->philo_num_eat = ft_atoi(argv[5]); //optional, look into its checks later



}