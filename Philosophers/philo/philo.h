/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopes-c <jlopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:53:52 by jlopes-c          #+#    #+#             */
/*   Updated: 2025/05/15 15:25:43 by jlopes-c         ###   ########.fr       */
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

typedef struct s_philo t_philo;

typedef struct s_info
{
	int philo_num;
	int philo_ttd;
	int philo_tte;
	int philo_tts;
	int philo_num_eat;
	pthread_mutex_t *forks; //think of forks like mutex locks
	t_philo	**philo;

	pthread_mutex_t print_lock;

} t_info;

typedef struct s_philo
{

	pthread_t thread;
	int times_ate;
	int id;
	int fork[2];
	int is_eating;
	int is_thinking;
	int is_sleeping;
	long long last_meal;
	pthread_mutex_t meal_lock;
	int is_dead;
	t_info *info;

} t_philo;


//Parsing
int	ft_atoi(const char *nptr);
int	ft_isdigit(char *str);
int is_valid(int argc, char **argv);

//Get Time
long long	get_time_in_ms(void);
void philo_sleep(int ms);


//Initialize

pthread_mutex_t *initialize_forks(t_info *data);
void give_forks(t_philo *data);
t_philo **initialize_philosophers(t_info *data);
void init_values(char **argv, t_info *data);

//Philo Routine
void eat_routine(t_philo *data);

#endif