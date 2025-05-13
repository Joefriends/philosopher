/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopes-c <jlopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:53:52 by jlopes-c          #+#    #+#             */
/*   Updated: 2025/05/13 12:53:53 by jlopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct s_info
{
	int philo_num;
	int philo_ttd;
	int philo_tte;
	int philo_tts;
	int philo_num_eat;
	pthread_mutex_t *forks; //think of forks like mutex locks
	t_philo	**philo;


	pthread_mutex_t philolock1;
	pthread_mutex_t philolock2;
	pthread_mutex_t philolock3;


} t_info;


typedef struct s_philo
{

	pthread_t thread;
	int is_eating;
	int is_thinking;
	int is_sleeping;
	int is_dead;
	t_info *table;

}	t_philo;



#endif