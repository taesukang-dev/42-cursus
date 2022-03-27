#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	del_buf(char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i])
	{
		s[i] = 0;
		i++;
	}
}

char	*get_one_line(char *s)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = s;
	while(*s && *s != '\n')
	{
		s++;
		i++;
	}
	temp[i] = '\0';
	return temp;
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*fd_table[OPEN_MAX] = {0, };
	char		buf[BUFFER_SIZE + 1];
	
	temp = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		temp = ft_strjoin(temp, buf);
		del_buf(buf);
	}
	fd_table[fd] = temp;
	return get_one_line(fd_table[fd]);
}

int main()
{
	char	*temp;
	int fd = open("./test.txt", O_RDONLY);
	if (fd > 0)
	{
		temp = get_next_line(fd);
		printf("%s", temp);
		temp = get_next_line(fd);
		printf("%s", temp);
		temp = get_next_line(fd);
		printf("%s", temp);
		temp = get_next_line(fd);
		printf("%s", temp);
		temp = get_next_line(fd);
		printf("%s", temp);
	}
	close(fd);
	free(temp);
	return 0;
}
