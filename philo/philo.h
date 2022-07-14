#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

// #define THINKING 0
// #define HUNGRY 1
// #define EATING 2

#define NUM_PHILS 5
enum {THINKING, HUNGRY, EATING} state[NUM_PHILS];

typedef struct s_args
{
	int fork;
	int eat_time;
	int die_time;
	int sleep_time;
	int eat_cnt;
} t_args;

void	exit_trap(int sig);
int		my_atoi(const char *str);

#endif
