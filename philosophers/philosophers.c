#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *justPlus(void *data)
{
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	*(int *)data += 1;
	printf("hi! %d\n", *(int *)data);

	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return (0);
}

void *justMinus(void *data)
{
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	*(int *)data -= 1;
	printf("hi! %d\n", *(int *)data);

	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return (0);
}

int main()
{
	pthread_t thread;
	pthread_t thread2;
	
	int a = 2;
	int status;
	
	pthread_create(&thread, NULL, justPlus, (void *)&a);
	pthread_create(&thread2, NULL, justMinus, (void *)&a);
	printf("%d\n", a);
	pthread_join(thread, (void **)&status); // 반환값 O, blocking
	
	// pthread_detach(thread); // 반환값 X, non-blocking

	return 0;
}