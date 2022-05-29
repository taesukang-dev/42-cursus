#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	child;

	// if (argc != 5)
	// 	return 0;
	
	// if (argc == 5)
	// {
	// 	ipc_info->infile = argv[1];
	// 	ipc_info->cmd[0].cmd = ft_split(argv[2], ' ');
	// 	ipc_info->cmd[1].cmd = ft_split(argv[3], ' ');
	// 	ipc_info->outfile = argv[4];
	// }

	// char *str[3];
	// str[0] = "ls";
	// str[1] = "-al";
	// str[2] = NULL;
	// execve("/bin/ls", str, NULL);

	if (pipe(fd) == -1)
		return 0;
	child = fork();
	if (child == -1)
		return 0;
	if (child == 0)
	{
		int test = open("./test.txt", O_WRONLY | O_CREAT | O_TRUNC);
		if (dup2(test, STDOUT_FILENO) == -1)
			printf("hi!");
		printf("hhh");
	}

	return 0;
}