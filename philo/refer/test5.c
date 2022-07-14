#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *threads(void *data)
{
	int i = *(int *)data;
	pthread_t tid = pthread_self();
	printf("hi I'm %d tid : %x\n", i, (unsigned int)tid);
	return 0;
}

int main()
{
	int res;
	pthread_t thread[5];

	for(int i = 0; i < 5; i++)
		pthread_create(&thread[i], NULL, threads, (int *)&i);

	// char s1[] = "s1";
	// char s2[] = "s2";
	// char s3[] = "s3";
	// char s4[] = "s4";
	// char s5[] = "s5";

	// pthread_create(&thread[0], NULL, threads, (void *)&s1);
	// pthread_create(&thread[1], NULL, threads, (void *)&s2);
	// pthread_create(&thread[2], NULL, threads, (void *)&s3);
	// pthread_create(&thread[3], NULL, threads, (void *)&s4);
	// pthread_create(&thread[4], NULL, threads, (void *)&s5);
		
	for(int i =0; i < 5; i++)
		pthread_join(thread[i], NULL);
	return 0;
}
