# Keyword
- process
- thread
- synchronous
- cf) Consumer-Producer Problem, Readers-Writers Problem

<br />

- 밥 먹기, 잠 자기, 생각하기
- 2개의 포크를 이용해서 먹음!
- 굶으면 안됨
- 서로 대화 불가
- 서로 언제 죽는지 모름
- 밥 다 먹으면 포크 내려놓고 잠잠
- 잠 다 자면 생각함
- 한 명이라도 사망하면 시뮬레이션 종료
- 다음과 같은 옵션을 가져야 한다
	- 철학자의 수 (number_of_philosophers): 테이블에 앉아 있는 철학자의 수와 포크의 수
	- 철학자의 수명 (time_to_die): 밀리초 단위, 마지막으로 밥을 먹은 후 time_to_die 시간만큼 지나거나, 시작 후 time_to_die 시간 지나면 사망
	- 밥을 먹는 데 걸리는 시간 (time_to_eat) : 밀리초 단위, 밥을 먹는 데 걸리는 시간, 2 개의 포크 소유해야 함
	- 잠자는 시간 (time_to_sleep) : 밀리초 단위, 잠을 자는 데 소모되는 시간
	- 각 철학자가 최소한 밥을 먹어야 하는 횟수 (number_of_times_each_philosopher_must_eat) : 선택사항, 모든 철학자가 number_of_times_each_philosopher_must_eat 만큼 밥 먹으면 시뮬레이션 종료

<br />

- 사용 가능 함수
	- string.h
		- memset
	- stdio.h
		- printf
	- stdlib
		- malloc
		- free
		- write
	- unistd.h
		- usleep
	- sys/time.h
		- gettimeofday
	- pthread.h
		- pthread_create
			- 쓰레드 생성
			- pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
		- pthread_detach
			- int pthread_join(pthread_t th, void **thread_return)
			- 인자로 받은 쓰레드를 부모 쓰레드로부터 독립시킴 (종료시 자동 리소스 해제)
			- 쓰레드가 종료되길 기다렸다가, 쓰레드가 종료되면 다음 명령어 진행
			- blocking
		- pthread_join
			- join과 동일한 기능이지만, non blocking
			- 반환값 처리 불가
			- pthread가 종료될 때까지 기다렸다가 종료될 때 자원 해제
		- pthread_mutex_init
			- pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutex_attr *attr)
			- 첫 인자 mutex, 2번 째 인자 mutex 특성 변경, attr 사용 못하니 NULL
		- pthread_mutex_destroy
			- int pthread_mutex_destroy(pthread_mutex_t *mutex)
			- mutex 삭제, 자원 돌려줌
		- pthread_mutex_lock
			- int pthread_mutex_lock(pthread_mutex_t *mutex)
			- mutex lock
			- 잠금을 얻을 수 있을 때까지 무한 대기
		- pthread_mutex_unlock
			- int pthread_mutex_unlock(pthread_mutex_t *mutex);
			- mutex unlock

<br />

- 젓가락을 공유하면서 race condition 발생
- mutex, deadlock, starvation
- 각 젓가락에 mutex 걸면 됨
- 양쪽 젓가락이 available 할 때 집는다.
- 홀수인 철학자는 왼쪽 -> 오른쪽 젓가락 집는다.
- 짝수인 철학자는 오른쪽 -> 왼쪽 젓가락을 집는다.
- 위의 해결법들은 deadlock 을 해결하진 못함
- pickup() 젓가락 집기, putdown() 젓가락 내려놓기
- 사람이 5명이면
- int chopstick[5];
- int chopstick[(i + 1) % 5]; 오른쪽
- int chopstick[(i + 4) % 5]; 왼쪽
- ac[1]; // philos
- ac[2]; // ages
- ac[3]; // time to eat
- ac[4]; // time to sleep
- ac[5]; // number of eat