#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *justPlus(void *data)
{
	pthread_mutex_t mutex;
	int num = *(int *)data;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	num += 1;
	printf("hi! %d\n", *(int *)data);

	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return ((void *)num);
}

void *justMinus(void *data)
{
	pthread_mutex_t mutex;
	int num = *(int *)data;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	num -= 1;
	printf("hi! %d\n", *(int *)data);

	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return ((void *)num);
}

int main(int ac, char *av[])
{
	// pthread_t philos[];
	// ac[1]; // philos
	// ac[2]; // ages
	// ac[3]; // time to eat
	// ac[4]; // time to sleep
	// ac[5]; // number of eat

	pthread_t thread;
	pthread_t thread2;
	
	int a = 2;
	int status = 0;
	
	if (pthread_create(&thread, NULL, justPlus, (void *)&a) == -1)
	{
		printf("fail");
	}
	pthread_create(&thread2, NULL, justMinus, (void *)&a);
	pthread_join(thread, (void *)&status); // 반환값 O, blocking
	pthread_join(thread2, (void *)&status); // 반환값 O, blocking
	printf("%d\n", status);
	// pthread_join(thread, (void **)&status); // 반환값 O, blocking
	// pthread_detach(thread); // 반환값 X, non-blocking
	return 0;
}