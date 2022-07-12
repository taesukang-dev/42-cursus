#include "philosophers.h"

pthread_mutex_t mutex;

void *justPlus(void *data)
{	
	int num = *(int *)data;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	num += 1;
	printf("hi! %d\n", num);

	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return ((void *)num);
}

void *justMinus(void *data)
{
	int num = *(int *)data;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	num -= 1;
	printf("hi! %d\n", num);

	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return ((void *)num);
}

int main(int ac, char *av[])
{
	pthread_t thread;
	// pthread_t philos[];

	for(int i = 0; i < NUM_PHILS; i++)
	{
		if(pthread_create(&thread, NULL, justPlus, (void *)&i) == -1)
			printf("fail");
	}
	for(int i = 0; i < NUM_PHILS; i++)
		pthread_join(thread, NULL);
	return 0;
}
