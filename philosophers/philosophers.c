#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *justPrint(void *data)
{
	printf("hi! %d", *(int *)data);
	return (0);
}

int main()
{
	pthread_t thread;
	pthread_mutex_t mutex;
	
	int a = 2;
	int status;
	
	pthread_create(&thread, NULL, justPrint, (void *)&a);
	pthread_join(thread, (void **)&status); // 반환값 O, blocking
	// pthread_detach(thread); // 반환값 X, non-blocking
	return 0;
}