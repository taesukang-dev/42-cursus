# Keyword

- linux pipe와 redirection을 구현하자!
- 멀티 프로세싱 맛보기!
- <a href="./subject.md">과제 전문</a>

# Blocking vs Nonblocking vs Async
- waitpid는 특정 자식 프로세스가 종료될 때 까지 대기하지만 WNOHANG 옵션을 통해서 함수를 바로 return 하고 자기 task를 수행한다.
- 그러다 자식 프로세스가 종료되면 status에 자식 프로세스 반환값 * 256을 입력한다.
- 즉, non blocking fork
- Synchronous
	- 작업 요청을 했을 때 요청의 결과값을 직접 받는 것이다.
	- 호출한 함수가 작업 완료를 신경 쓴다.
- Asynchronous
	- 작업 요청을 했을 때 요청의 결과값을 간접적으로 받는 것이다.
	- 요청의 결과값과 return 값이 다를 수 있다.
	- 호출된 함수(callback 함수)가 작업 완료를 신경쓴다.
	- e.g. 이메일로 물어보고 메일 송신을 완료(return)했지만 답은 언제 올지 모른다.
- blocking
	- 요청한 작업을 마칠 때까지 계속 대기한다.
	- return 값을 받아야 끝난다.
	- 호출된 함수가 자신의 작업을 모두 마칠 때까지 호출한 함수에게 제어권을 넘겨주지 않고 대기하게 만드는 것.
	- e.g. 전화를 받을 때까지 계속 대기 후 답을 얻는다.
- non-blocking
	- 요청한 작업을 즉시 마칠 수 없다면 바로 return한다.
	- 결과가 완료 되었는지 지속적으로 확인한다.
	- 호출된 함수가 바로 return해서 호출한 함수에게 제어권을 넘겨주고 호출한 함수가 다른 일을 할 수 있게 기회를 주는 것.
	- e.g. 전화를 했는데 받지 않아서 계속 반복 전화하다가 어느 순간 받아서 답을 얻는다.

## pipe <unistd.h>

- `int pipe(int filedes[2]);`
- 프로세스 간 통신 (IPC) 에서 사용하는 파이프 생성 (message passing...?)
- pipe() 에서 생성하는 파이프는 프로세스에서 생성되는 것이 아니라 커널에서 생성되고, 이용할 수 있는 파일 디스크럽터만 제공된다.
- 그러므로 하나의 프로세스에서 파이프를 생성했다면, 다른 프로세스에서 그 FD를 사용하여 통신한다.
- 반환된 FD는 파일에 대한 FD가 아닌 운영체제로부터 할당 받은 특정 버퍼에 대한 FD이다.
- 또한 이 FD는 입출력 방향이 결정되어 있다.
- 입력과 출력을 위한 입출구가 따로 존재하고, FIFO 구조로 데이터를 주고 받는다.

```C
int pipe(int filedes[2]);

filedes[0] // 읽기 전용
filedes[1] // 쓰기 전용
```

## fork <unistd.h>

- `pid_t fork(void);`
- 현재 프로세스에 대한 복사본 프로세스를 생성한다.
- 대체로 자식 프로세스라고 부른다.
- 반환 값은 자식프로세스의 pid (자료형 pid_t, 0 ~ 32767 || -1 ~ 32768, int도 됨...)
- 실패할 경우 반환값은 -1
- 자식 프로세스는 fork 함수 호출 이후부터 진행하기 때문에 pid를 저장한 변수 값은 자식 프로세스에서 확인했을 때에는 0

## wait, waitpid <sys/wait.h>

- `pid_t wait(int *status);`
- `pid_t waitpid(pid_t pid, int *status, int options);`
- wait은 자식 프로세스가 작업이 끝날 때 까지 대기하고, 자식 프로세스를 수거하여 종료한 상태를 구한다.
- 정상 종료 되었다면, status의 변수 값의 상위 2번째 index인 1바이트에 종료 값을 저장하고, 3번째 index인 1바이트에 종료 코드를 저장한다. (8비트)
  - 다만 위의 경우는 쉬프트 연산을 제공하는 메크로로 해석해서 볼 수 있다. (e.g. WEXITSTATUS)
- waitpid 는 자식 프로세스 중 어느 하나라도 종료되면 복귀되는 wait과는 다르게 특정 자식이 종료될 때까지 대기한다.
- 또한 wait은 자식 프로세스가 종료될 때까지 block 되지만, waitpid는 WNOHANG 옵션을 통해 block되지 않고 다른 작업을 진행할 수 있다.
- wait 함수는 자식프로세스가 좀비 프로세스 상태로 되는 것을 방지한다. 자식프로세스가 종료됐을지라도 부모프로세스가 진행중이라면 자식프로세스는 반환값을 지닌채 좀비프로세스 상태로 대시하고 있다. 그 때, wait 함수의 인자를 통해 자식프로세스의 반환값과 데이터등을 받아오면 자식프로세스는 데이터를 넘겨주고 좀비 프로세스 상태에서 벗어날 수 있다.

```C
// 정상 종료를 확인하는 코드는 다음과 같이 수정할 수 있습니다.
if ( 0 == ( status & 0xff))  ->  if ( WIFEXITED( status))

// 자식이 반환한 코드를 아래와 같이 바꿀 수 있습니다.
status >> 8    ->    WEXITSTATUS( status)

// 출처 : https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%9E%90%EC%8B%9D-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EA%B0%80-%EC%A2%85%EB%A3%8C%EB%90%A0-%EB%95%8C%EA%B9%8C%EC%A7%80-%EB%8C%80%EA%B8%B0-%ED%95%A8%EC%88%98-wait
```

## dup, dup2 <unistd.h>

- `int dup(int fildes)`
- `int dup2(int fd, int fd2)`
- fildes == fd
- 파일 디스크립터의 복사본을 만든다.
- 원본 디스크립터와 복사된 디스크립터의 읽기/쓰기 포인터는 공유된다. (원본에 똑같이 쓸 수 있다, 정확히는 fd가 가리키는 inode가 같다.)
- 사용하지 않는 가장 작은 파일 디스크립터 번호가 임의로 지정된다.
- close는 각각 해줘야 한다.
- cf) dup2는 기능은 동일하지만, fd 값을 지정한 곳에 복사할 수 있다.
- dup2의 반환값은 fd2가 된다.
- 만약 2번째 인자의 fd 값이 열려있다면 기존 fd를 닫고 새로 할당받는다.
- stdout의 경우 가리키던 terminal 에서 복제된 fd의 inode, stdin의 경우 가리키던 I/O device에서 복제된 fd의 inode
  - 표준 스트림 (stdin, stdout, stderr) 은 shell에서 상속 받는다.
  - DMA...?

## access <unistd.h>

- `int access(const char *pathname, int mode);`
- 프로세스가 지정한 파일이 존재하는지, 읽거나 쓰거나 실행이 가능한 지 확인하는 함수.
- 만일 지정한 파일이 심볼릭 링크라면 링크의 원본을 체크한다.
- 인수 pathname : 파일이나 디렉토리 전체 이름, mode : 검사할 내용
- 반환 0 : 가능, 파일이 존재함
- 반환 -1 : mode 에 대해 하나 이상 거절되었거나 에러가 있음, 자세한 내용은 errno 에 셋팅

## unlink <unistd.h>

- `int unlink(const char *path);`
- 하드링크를 삭제하는 함수.
- 만약 하드링크가 남아있지 않다면 당연하게 파일이 삭제된다.
- cf) 심볼릭 링크는 별도의 아이노드를 갖고 있고, 그 아이노드는 하드 링크의 inode를 참조한다.
- 인수 : char \*path, 삭제하려는 링크 이름
- 반환 0 : 성공
- 반환 -1 : 실패

## execve <unistd.h>

- `int execve(const char *path, char *const argv[], char *const envp[]);`
- path를 실행하고 자신은 종료한다.
- 만들어진 path 프로세스는 새로운 메모리 공간을 갖는다. (스택, 힙, 데이터)
- 이 떄 별도의 프로세스가 구동되는 것이 아닌 새로운 프로세스를 교체하는 행위로 이뤄지기 때문에 동기적인 특성을 갖는다.
- 인자는 각각 파일이름, 파일인자의 포인터, 환경변수의 포인터이다.
- path의 파일(바이너리 실행파일이거나, 스크립트 파일이어야 한다.)을 실행하고, argv envp를 인자로 전달한다.
- exec 계열은 l, v, e, p 가 붙을 수 있는데 각각 list, vector, environment, path 이다.
- 끝은 항상 NULL 이어야 한다.

```C
int main()
{
	int fd1[2];
	int fd2[2];
	char buffer[BUFSIZ];
	pid_t pid;

	if (pipe(fd1) == -1 || pipe(fd2) == -1)
	{
		printf("pipe error");
		exit(1);
	}
	pid = fork();

	if (pid == -1)
	{
		printf("fork() error");
		exit(1);
	}
	if (pid == 0)
	{
		write(fd1[1], "자식에서 입력 \n", 25);
		read(fd2[0], buffer, 25);
		// 만약 부모에서 쓰지 않으면 여기에서 대기 중으로 실행 안됨
		// 읽을 fd가 있을 때 까지 대기
		printf("\n자식 출력 : %s\n", buffer);
	}
	else
	{
		// write(fd2[1], "부모에서 입력 \n", 25);
		read(fd1[0], buffer, BUFSIZ);
		printf("\n부모 출력 : %s\n", buffer);
	}
	return 0;
}
```

```C
int main()
{
	int fd1[2];
	int fd2[2];
	char buffer[BUFSIZ];
	pid_t pid;

	if (pipe(fd1) == -1 || pipe(fd2) == -1)
	{
		printf("pipe error");
		exit(1);
	}
	pid = fork();

	if (pid == -1)
	{
		printf("fork() error");
		exit(1);
	}
	if (pid == 0)
	{
		write(fd1[1], "자식에서 입력 \n", 25);
		read(fd2[0], buffer, 25);
		// 만약 부모에서 쓰지 않으면 여기에서 대기 중으로 실행 안됨
		// 읽을 fd가 있을 때 까지 대기
		printf("\n자식 출력 : %s\n", buffer);
	}
	else
	{
		wait(NULL); // 자식 프로세스가 끝날 때 까지 대기로 무한대기
		write(fd2[1], "부모에서 입력 \n", 25);
		// wait(NULL); 이 상태에서는 실행 가능
		read(fd1[0], buffer, BUFSIZ);
		printf("\n부모 출력 : %s\n", buffer);
	}
	return 0;
}
```

### 참고

- `int main(int argc, char *argv[], char *envp[]);` envp는 환경변수
  - 인자 3개는 POSIX 표준이 아니다.
  - https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html
  - https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html
- `extern char **environ;` 전역으로 environ, 환경변수 가져올 수 있음
- `<` : stdin, `<` 기호의 다음을 source로 사용 (cat, grep...etc)
  - ls 는 표준 입력을 받지 않고, argv를 통해서 사용자 입력을 받는다.
- `>` : stdout
