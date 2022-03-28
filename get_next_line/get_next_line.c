#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_one_line(char **s, int nl_pivot)
{
	char	*temp;
	size_t	i;
	
	temp = (char *)malloc(sizeof(char) * nl_pivot + 1);
	i = 0;
	while((*s)[i] && (*s)[i] != '\n')
	{
		temp[i] = (*s)[i];
		i++;
	}
	i = 0;
	while(i <= nl_pivot)
	{
		(*s)++;
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
	while(s[i] && s[i] != '\n')
		i++;
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

	while(1)
	{
		nl_pivot = ft_find_nl(fd_table[fd]);
		if (nl_pivot >= 0)
			return get_one_line(&fd_table[fd], nl_pivot);
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break;
		buf[read_len] = '\0';
		fd_table[fd] = ft_strjoin(fd_table[fd], buf);
		if (!fd_table[fd])
			return (NULL);
	}
	return fd_table[fd];
}

int main()
{
	char	*temp;
	int fd = open("./test.txt", O_RDONLY);
	if (fd > 0)
	{
		temp = get_next_line(fd);
		printf("%s\n", temp);
		temp = get_next_line(fd);
		printf("%s\n", temp);
		temp = get_next_line(fd);
		printf("%s\n", temp);
		temp = get_next_line(fd);
		printf("%s\n", temp);
		temp = get_next_line(fd);
		printf("%s\n", temp);
	}
	close(fd);
	return 0;
}
