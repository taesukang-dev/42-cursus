#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *data)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	char *thread_name = (char *)data;
	int i = 0;

	while(i < 3) // 0, 1, 2 까지만 loop!
	{
		// 넘겨받은 쓰레드 이름과
		// 현재 process id와 thread id를 함께 출력
		printf("[%s] pid : %u, tid : %x --- %d\n", thread_name, (unsigned int)pid, (unsigned int)tid, i);
		i++;
		sleep(1);
	}
	return 0;
}

int main()
{
	pthread_t p_thread[2];
	int thr_id;
	int status;
	char p1[] = "thread_1"; // 1번 쓰레드 이름
	char p2[] = "thread_2"; // 2번 쓰레드 이름
	char pM[] = "thread_m"; // 메인 쓰레드 이름

	sleep(1);
	// 1번 쓰레드 생성
	// 쓰레드 생성시 함수는 t_function
	// t_function 의 매개변수로 p1을 넘긴다.
	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)p1);

	// pthread_create() 로 성공적으로 쓰레드가 생성되면 0이 리턴됩니다.
	if(thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}

	// 2번 쓰레드 생성
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)p2);
	if(thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}

	// main() 함수에서도 쓰레드에서 돌아가고 있는 동일한 함수 실행
	t_function((void *)pM);

	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);

	printf("언제 종료될까요?\n");

	return 0;
}