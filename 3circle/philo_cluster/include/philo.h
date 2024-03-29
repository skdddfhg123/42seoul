/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:18:55 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/24 15:53:43 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int					idx;
	int					is_die;
	int					eat_done;
	int					cnt;
	pthread_t			thread;
	long long			meal_time;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					philo_num;
	long long			die_t;
	long long			eat_t;
	long long			sleep_t;
	long long			must_eat;
	long long			start_time;
	int					is_fin;
	int					fin_philo;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printer;
	t_philo				*philo;
}						t_data;

int			err_print(char *err);
int			ft_free(t_data **data);

int			init_data(int argc, char **argv, t_data **data);
int			init_philo(t_data *data);

void		*monitor(void *argv);

void		start(t_data *data);

int			ft_isdigit(int c);
int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
long long	get_time(void);
void		print_philo(t_philo *philo, char *str);

#endif