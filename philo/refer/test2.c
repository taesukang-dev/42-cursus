#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int ncount; // 쓰레드간 공유되는 자원
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 쓰레드 초기화

void* do_loop(void *data)
{
	for(int i = 0; i < 10; i++)
	{
		pthread_mutex_lock(&mutex); // 잠금을 생성한다.
		printf("loop1 : %d\n", ncount);
		ncount++;
		pthread_mutex_unlock(&mutex); // 잠금을 해제한다.
		sleep(1);
	}
	return 0;
}

void* do_loop2(void *data)
{
	for(int i = 0; i < 10; i++)
	{
		// 잠금을 얻으려고 하지만 do_loop 에서 이미 잠금을 얻었음으로 잠금이 해제될 때까지 기다린다.
		pthread_mutex_lock(&mutex);
		printf("loop2 : %d\n", ncount);
		ncount++;
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
	return 0;
}

int main()
{
	int thr_id;
	pthread_t p_thread[2];
	int status;
	int a = 1;

	ncount = 0;
	thr_id = pthread_create(&p_thread[0], NULL, do_loop, (void *)&a);
	sleep(1);
	thr_id = pthread_create(&p_thread[1], NULL, do_loop2, (void *)&a);

	// 쓰레드가 종료되면 자원 반납
	pthread_join(p_thread[0], (void *)&status);
	pthread_join(p_thread[1], (void *)&status);

	// 뮤텍스 파괴
	status = pthread_mutex_destroy(&mutex);
	printf("code = %d ",status);
	printf("programing is end");
	return 0;
}