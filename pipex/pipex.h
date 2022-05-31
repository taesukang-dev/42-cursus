#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

void	exit_trap(char *str);
void	two_d_free(char **temp);
char	*set_up_path(char *cmd, char *envp[]);
void	run_cmd(char *argv, char *envp[]);
void	child_process(char *argv[], char *envp[], int *fd);
void	parent_process(char *argv[], char *envp[], int *fd);

#endif