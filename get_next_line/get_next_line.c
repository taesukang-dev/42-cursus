#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_one_line(char *s, int nl_pivot)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * nl_pivot);
	while(*s && *s != '\n')
	{
		temp[i] = *s;
		s++;
		i++;
	}
	temp[i] = '\0';
	return temp;
}

int	ft_find_nl(char *s)
{
	size_t	i;

	if (!s)
		return -1;
	i = 0;
	while(s[i] != '\n')
	{
		i++;
	}
	if (s[i])
		return i;
	return -1;
}

char	*get_next_line(int fd)
{
	static char	*fd_table[OPEN_MAX] = {0, };
	char		buf[BUFFER_SIZE + 1];
	int			read_len;
	int			nl_pivot;

	read_len = read(fd, buf, BUFFER_SIZE);
	ft_strlcpy(&fd_table[fd], buf);
	nl_pivot = ft_find_nl(fd_table[fd]);
	if (nl_pivot >= 0)
		return get_one_line(fd_table[fd], nl_pivot);	
	return fd_table[fd];
}

int main()
{
	char	*temp;
	int fd = open("./test.txt", O_RDONLY);
	if (fd > 0)
	{
		temp = get_next_line(fd);
		printf("the temp is %s\n", temp);
		temp = get_next_line(fd);
		printf("the temp is %s\n", temp);
		temp = get_next_line(fd);
		printf("the temp is %s\n", temp);	
	}
	close(fd);
	free(temp);
	return 0;
}
