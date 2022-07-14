#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5

pthread_mutex_t mutexes[NUM_THREADS]; //mutex를 사용한다고 선언, pthread_mutex_t 자료형임.
pthread_cond_t conditionVars[NUM_THREADS]; // 데이터형은 pthread_cond_t 이다. 뮤텍스 정적 초기화

int permits[NUM_THREADS]; //포크 사용여부
pthread_t tids[NUM_THREADS]; // 스레드 담을 그릇

void pickup_forks(int philosopher_number) 
{
	pthread_mutex_lock(&mutexes[philosopher_number % NUM_THREADS]);
	//못쓰면 wait를 걸어 mutexes락을 해제합니다.이 스레드는 잠시 뒤로 미뤄두고 conditionVars를 기다립니다.
	while(permits[philosopher_number % NUM_THREADS] == 0)
		pthread_cond_wait(&conditionVars[philosopher_number % NUM_THREADS], &mutexes[philosopher_number % NUM_THREADS]);
	permits[philosopher_number % NUM_THREADS] = 0;
	pthread_mutex_unlock(&mutexes[philosopher_number % NUM_THREADS]);
}

void return_forks(int philosopher_number) 
{
	pthread_mutex_lock(&mutexes[philosopher_number % NUM_THREADS]);
	permits[philosopher_number % NUM_THREADS] = 1;
	pthread_cond_signal(&conditionVars[philosopher_number % NUM_THREADS]);
	pthread_mutex_unlock(&mutexes[philosopher_number % NUM_THREADS]);
}

void *OddPhilosopher(void *data)
{
	int philosopher_number = *(int *)data;

	// pickup right fork
	pickup_forks(philosopher_number + 1);
	printf("philosopher(%d) picks up the fork(%d)\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);

	// pickup left fork
	pickup_forks(philosopher_number);
	printf("philosopher(%d) picks up the fork(%d)\n", philosopher_number, philosopher_number);

	printf("philosopher(%d) starts eating \n", philosopher_number);
	sleep(2);
	printf("philosopher(%d) starts eating \n", philosopher_number);

	// putdown left fork
	return_forks(philosopher_number);
	printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, philosopher_number);

	// putdown right fork
	return_forks(philosopher_number + 1);
	printf("philosopher(%d) put down the fork (%d) \n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
	
	return 0;
}

void *Philosopher(void *data)
{
	int philosopher_number = *(int *)data;

	// pickup left fork
	pickup_forks(philosopher_number);
	printf("philosopher(%d) picks up the fork(%d)\n", philosopher_number, philosopher_number);

	// pickup right fork
	pickup_forks(philosopher_number + 1);
	printf("philosopher(%d) picks up the fork(%d)\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);

	printf("philosopher(%d) starts eating \n", philosopher_number);
	sleep(2);
	printf("philosopher(%d) starts eating \n", philosopher_number);

	// putdown right fork
	return_forks(philosopher_number + 1);
	printf("philosopher(%d) put down the fork (%d) \n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);

	// putdown left fork
	return_forks(philosopher_number);
	printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, philosopher_number);

	return 0;
}

int main()
{
	int i;

	for(int i = 0; i < NUM_THREADS; i++)
	{
		pthread_mutex_init(&mutexes[i], NULL); // 뮤텍스 초기화
		pthread_cond_init(&conditionVars[i], NULL); // 조건변수 초기화
		permits[i] = 1; // 우선 모두 사용 가능
	}

	// 모두 초기화 했다. 이제 스레드를 생성해보자.
	for(int i = 0; i < NUM_THREADS; i++)
	{
		if (i % 2)
			pthread_create(&tids[i], NULL, OddPhilosopher, (void *)&i);
		else
			pthread_create(&tids[i], NULL, Philosopher, (void *)&i);
	}

	// 쓰레드가 전부 끝나야 함
	for(int i = 0; i < NUM_THREADS; i++)
		pthread_join(tids[i], NULL);
	
	for(int i = 0; i < NUM_THREADS; i++)
	{
		pthread_mutex_destroy(&mutexes[i]);
		pthread_cond_destroy(&conditionVars[i]);
	}

	return 0;
}