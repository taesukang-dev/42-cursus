# ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "./libft/libft.h"

typedef struct s_cmd
{
	char	**cmd;
	int		slash;
} t_cmd;

typedef struct s_ipc
{
	char	*infile;
	t_cmd	cmd[2];
	char	*outfile;
	char	**environ;
} t_ipc;

#endif