#include "pipex.h"

// char *str[3];
// str[0] = "ls";
// str[1] = "-al";
// str[2] = NULL;
// execve("/bin/ls", str, NULL);

// infile -> child process stdin으로 사용한다.
// fd[1] -> stdout 으로 쓴다
void child_process(char *argv[], char *envp[], int *fd)
{
	int infile;
	char **temp;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		return ;
	// if (dup2(fd[1], STDOUT_FILENO) == -1)
	// 	return ;
	// if (dup2(infile, STDIN_FILENO) == -1)
	// 	return ;
	
	temp = ft_split(argv[2], ' ');
	// temp[0];
	for(int i = 0; temp[i]; i++)
		printf("%s\n", temp[i]);
	
	int i = 0;
	while(ft_strncmp(envp[i], "PATH", 4))
		i++;
	char *path = envp[i] + 5;
	char **pathes = ft_split(path, ':');
	// for(int i = 0; pathes[i]; i++)
	// 	printf("%s\n", pathes[i]);
	i = 0;
	char *cmd = ft_strjoin("/", temp[0]);
	while(pathes[i])
	{
		char *check = ft_strjoin(pathes[i], cmd);
		if (!access(check, X_OK))
			execve(check, temp, NULL);
		i++;
	}
	close(fd[0]);
}

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	child;

	if (argc != 5)
		return 0;
	if (pipe(fd) == -1)
		return 0;
	child = fork();
	if (child == -1)
		return 0;
	if (child == 0)
		child_process(argv, envp, fd);
	waitpid(child, NULL, 0);
	
	// char buf[30];
	// read(fd[0], buf, 3);
	// printf("\n%s\n", buf);
	return 0;
}