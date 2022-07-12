#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// #define THINKING 0
// #define HUNGRY 1
// #define EATING 2

#define NUM_PHILS 5
enum {THINKING, HUNGRY, EATING} state[NUM_PHILS];

#endif