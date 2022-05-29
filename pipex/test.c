#include "pipex.h"

int main(int argc, char *argv[])
{
	extern char **environ;
	t_ipc	*ipc_info;

	ipc_info = ft_calloc(1, sizeof(t_ipc));
	ipc_info->environ = environ;
	if (argc == 5)
	{
		ipc_info->infile = argv[1];
		ipc_info->cmd[0].cmd = ft_split(argv[2], ' ');
		ipc_info->cmd[1].cmd = ft_split(argv[3], ' ');
		ipc_info->outfile = argv[4];
	}
	

	return 0;
}