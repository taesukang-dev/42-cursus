#include "pipex.h"

void	exit_trap(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	two_d_free(char **temp)
{
	int	i;

	i = 0;
	while(temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

char	*set_up_path(char *cmd, char *envp[])
{
	int		i;
	char	**paths;
	char	*check;
	
	i = 0;
	while(ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while(paths[i])
	{
		check = ft_strjoin(paths[i], cmd);
		if (!access(check, X_OK))
		{
			two_d_free(paths);
			return (check);
		}
		free(check);
		i++;
	}
	two_d_free(paths);
	return (NULL);
}

void	run_cmd(char *argv, char *envp[])
{
	char *cmd;
	char *path;
	char **temp;

	temp = ft_split(argv, ' ');
	cmd = ft_strjoin("/", temp[0]);
	path = set_up_path(cmd, envp);
	free(cmd);
	if (!path)
	{
		two_d_free(temp);
		exit_trap("path error\n");
	}
	if(execve(path, temp, NULL) == -1)
		exit_trap("excute error\n");
}

void child_process(char *argv[], char *envp[], int *fd)
{
	int infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		exit_trap("file error\n");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit_trap("duplicate error\n");
	if (dup2(infile, STDIN_FILENO) == -1)
		exit_trap("duplicate error\n");
	close(fd[0]);
	run_cmd(argv[2], envp);
}

void parent_process(char *argv[], char *envp[], int *fd)
{
	int outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit_trap("file error\n");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_trap("duplicate error\n");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit_trap("duplicate error\n");
	close(fd[1]);
	run_cmd(argv[3], envp);
}

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	child;

	if (argc != 5)
		exit_trap("not enough arguments\n");
	if (pipe(fd) == -1)
		exit_trap("pipe error\n");
	child = fork();
	if (child == -1)
		exit_trap("fork error\n");
	if (child == 0)
		child_process(argv, envp, fd);
	waitpid(child, NULL, 0);
	parent_process(argv, envp, fd);
	return 0;
}