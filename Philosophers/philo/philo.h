# ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


typedef struct s_philo //prob gonna use lists with this
{
	int philo_num;
	int philo_ttd;
	int philo_tte;
	int philo_tts;
	int philo_num_eat;
	int forks;
	int is_eating;
	int is_thinking;
	int is_sleeping;

	pthread_mutex_t philolock1;
	pthread_mutex_t philolock2;
	pthread_mutex_t philolock3;


} t_philo;




#endif