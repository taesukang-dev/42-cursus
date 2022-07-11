# Keyword
- process
- thread
- synchronous

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
	- memset
	- printf
	- malloc
	- free
	- write
	- usleep
	- gettimeofday
	- pthread_create
	- pthread_detach
	- pthread_join
	- pthread_mutex_init
	- pthread_mutex_destroy
	- pthread_mutex_lock
	- pthread_mutex_unlock