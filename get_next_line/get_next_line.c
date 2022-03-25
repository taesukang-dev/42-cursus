#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buf;
	char	c;
	size_t	i;

	buf = malloc(sizeof(char) * 42);
	i = 0;
	while(read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			buf[i] = '\0';
			break;
		}
		else
		{
			buf[i] = c;
			i++;
		}
	}
	return buf;
}

int main()
{
	char	*temp;
	int fd = open("./test.txt", O_RDONLY);
	if (fd > 0)
		temp = get_next_line(fd);
	close(fd);
	printf("%s", temp);
	free(temp);
	return 0;
}