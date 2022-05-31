/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:48:52 by tkang             #+#    #+#             */
/*   Updated: 2022/05/31 15:48:53 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_trap(char *str, int sig)
{
	write(2, str, ft_strlen(str));
	exit(sig);
}

void	two_d_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
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
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
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
	char	*cmd;
	char	*path;
	char	**temp;

	temp = ft_split(argv, ' ');
	if (!access(temp[0], X_OK))
	{
		if (execve(temp[0], temp, envp) == -1)
			exit_trap("excute error\n", 127);
	}
	cmd = ft_strjoin("/", temp[0]);
	path = set_up_path(cmd, envp);
	free(cmd);
	if (!path)
	{
		two_d_free(temp);
		exit_trap("command not found\n", 127);
	}
	if (execve(path, temp, envp) == -1)
		exit_trap("excute error\n", 127);
}
