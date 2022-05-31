/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:48:32 by tkang             #+#    #+#             */
/*   Updated: 2022/05/31 15:48:33 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], char *envp[], int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		exit_trap("file error\n", 1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit_trap("duplicate error\n", 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		exit_trap("duplicate error\n", 1);
	close(fd[0]);
	run_cmd(argv[2], envp);
}

void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit_trap("file error\n", 1);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_trap("duplicate error\n", 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit_trap("duplicate error\n", 1);
	close(fd[1]);
	run_cmd(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	child;

	if (argc != 5)
		exit_trap("arguments error\n", 1);
	if (pipe(fd) == -1)
		exit_trap("pipe error\n", 1);
	child = fork();
	if (child == -1)
		exit_trap("fork error\n", 1);
	if (child == 0)
		child_process(argv, envp, fd);
	waitpid(child, NULL, WNOHANG);
	parent_process(argv, envp, fd);
	return (0);
}
