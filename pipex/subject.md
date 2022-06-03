# page 0

Pipex
Pipex

Summary: This project is the discovery in detail and by programming of a UNIX mechanism that you already know.
요약 : 이 프로젝트는 여러분이 이미 알고 계시는 UNIX 매커니즘을 더 자세히 알아가는 프로젝트입니다.

# page 1

| 챕터  | 내용                     | 페이지 |
| :---: | :----------------------- | :----: |
|   I   | [**서문**]()             |   2    |
|  II   | [**기본 지시사항**]()    |   3    |
|  III  | [**목표**]()             |   5    |
| III.I | [**예시**]()             |   5    |
|  IV   | [**보너스 파트**]()      |   6    |
|   V   | [**제출 및 동료평가**]() |   7    |

# page 2

Cristina: "Go dance salsa somewhere :)"
크리스티나 : "어디 살사춤이나 추러 가자 :)"

# page 3

Chapter II
챕터 2
Common Instructions
기본 지시사항

• Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
• 여러분의 프로젝트는 Norminette 기준에 따라 작성되어야 합니다. 보너스 파일이나 함수가 있는 경우, 해당 파일/함수도 Norminette 기준을 체크하는 데에 포함해야 하며, Norminette 에러가 발생할 시에는 여러분의 프로젝트는 0점을 받게 됩니다.

• Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
• 정의되지 않는 동작인 경우 이외에는 여러분이 작성하신 프로그램이 예기치 않게 종료되면 안됩니다 (segmentation fault, bus error, double free 등). 만약 여러분의 프로그램이 예기치 않게 종료된다면, 작동하지 않은 것으로 간주되어 평가에서 0점을 받게 됩니다.

• All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
• 힙에 선언한 모든 메모리 영역은 free로 처리되어야 합니다. 메모리 누수는 용납되어서는 안됩니다.

• If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink.
• 서브젝트가 요구할 시 Makefile을 제출하여야 합니다. 여러분이 작성하신 Makefile은 `-Wall -Wextra -Werror` 플래그에 따라 컴파일을 해야하며, 컴파일 이후에 다시 리링크되지 않아야 합니다.

• Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
• 여러분이 작성하신 Makefile 에서는 다음의 룰을 정의하고 있어야 합니다. - `$(NAME), all, clean, fclean, re`

• To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h}. Mandatory and bonus part evaluation is done separately.
• 프로젝트에 보너스를 제출하려면, Makefile에 `bonus` 규칙을 포함해야하며, 해당 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리,또는 함수들을 Makefile에 추가할 수 있습니다. 보너스는 반드시 \_bonus.{c/h} 라는 다른 파일에 있어야 합니다. 필수 파트와 보너스 파트는 개별적으로 평가될 것입니다.

• If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
• 해당 프로젝트에서 `libft`를 사용하는 경우, 해당 라이브러리의 소스와 Makefile을 `libft` 폴더에 복사해야 합니다. 프로젝트의 Makefile은 Makefile을 사용하여 라이브러리를 컴파일한 다음에 여러분이 작성하신 프로젝트를 컴파일 해야합니다.

• We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
• `제출할 필요가 없고 채점되지 않더라도` 우리는 여러분이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이 프로그램은 여러분의 과제물과 동료들의 과제물을 쉽게 검증할 기회를 제공할 것입니다. 평가하는 동안 이 테스트 프로그램들이 특히 유용하다는 것을 알게 될 것입니다. 평가 중에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 자유롭게 사용할 수 있습니다.

• Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.
• 할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 채점 할 것입니다. Deepthought가 평가를 하게 된다면, 동료평가 이후에 수행됩니다. 만약 Deepthought가 평가 중 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

• The executable files must be named client and server.
실행파일은 각각 `pipex`로 이름을 지어야 합니다.

# page 4

• You have to handle errors sensitively. In no way can your program quit unexpectedly (Segmentation fault, bus error, double free, etc). If you are unsure, handle the errors like the shell command < file1 cmd1 | cmd2 > file2.
• 여러분은 세심하게 에러를 처리하셔야 하며, 여러분이 작성하신 프로그램이 예기치 않게 종료되면 안됩니다 (Segmentation fault, bus error, double free, 등). 확실하게 잘 모르겠다면, 쉘에서 다음과 같은 명령어에서 나오는 오류들을 처리해보세요 : `< file1 cmd1 | cmd2 > file2`

• Your program cannot have memory leaks.
• 여러분이 작성하신 프로그램에서 메모리 누수가 발생하면 안됩니다.

• You are allowed to use the following functions:
• 다음의 함수만을 사용하실 수 있습니다. :

    ◦ open
    ◦ close
    ◦ read
    ◦ write
    ◦ malloc
    ◦ free
    ◦ dup2
    ◦ execve
    ◦ fork
    ◦ perror
    ◦ strerror
    ◦ exit

# page 5

Chapter III
챕터 3
Objectives
목표

Your objective is to code the Pipex program.
여러분의 목표는 Pipex 프로그램을 작성하는 것입니다.
It should be executed in this way:
여러분이 작성하신 프로그램은 다음과 같이 실행될 것입니다. :

    $> ./pipex file1 cmd1 cmd2 file2

Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.
예를 들어, `file1`및 `file2`는 파일 이름이고 `cmd1` 및 `cmd2`는 매개변수에 대응하는 Shell 명령어 입니다.

The execution of the pipex program should do the same as the next shell command:
여러분의 Pipex 프로그램은 아래의 명령을 Shell에서 실행되는 것과 동일하게 처리해야 합니다.

    $> < file1 cmd1 | cmd2 > file2

III.1 Examples
III.1 예시

     $> ./pipex infile ``ls -l'' ``wc -l'' outfile

should be the same as “< infile ls -l | wc -l > outfile”
`< infile ls -l | wc -l > outfile`의 결과와 동일해야 합니다.

     $> ./pipex infile ``grep a1'' ``wc -w'' outfile

should be the same as “< infile grep a1 | wc -w > outfile”
`< infile grep a1 | wc -w > outfile`의 결과와 동일해야 합니다.

# page 6

Bonuses will be evaluated only if your mandatory part is PERFECT.
By PERFECT we naturally mean that it needs to be complete, that it
cannot fail, even in cases of nasty mistakes like wrong uses, etc.
It means that if your mandatory part does not obtain ALL the points
during the grading, your bonuses will be entirely IGNORED.

```
⚠️
보너스는 필수로 구현해야 하는 파트가 완벽할 때만 평가될 것입니다. 저희가 말하는 '완벽함' 이란, 어떠한 경우에도 - 잘못된 사용과 같은 끔찍한 실수 등 - 실패하지 않고 동작해야 한다는 의미입니다. 쉽게 말하자면, 필수로 구현해야 하는 파트에서 만점을 받지 못한다면, 보너스는 완전히 '무시될' 것입니다.
```

• Handle multiple pipes :
• 다중 파이프 구현하기 :

    $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

    Must be equivalent to :
    위의 명령어는 다음에 상응해야 합니다. :

    < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

• Support « and ».
• « 와 » 구현하기.

# page 7

Chapter V
챕터 4
Submission and peer correction
제출과 동료평가

Submit your work on your GiT repository as usual. Only the work on your repository will be graded.
평소처럼 여러분의 GIT 레포지토리에 작업물을 제출하시면 됩니다. 제출하신 작업물만 평가에 반영될 것입니다.
