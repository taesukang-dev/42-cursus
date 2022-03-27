#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	i = 0;
	while(s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		temp[s1_len] = s2[i];
		i++;
		s1_len++;
	}
	temp[s1_len] = '\0';
	return (temp);
}

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
	char		*buf = malloc(sizeof(char) * BUFFER_SIZE);
	char		*temp;
	static char	*fd_table[OPEN_MAX];
	
	temp = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		temp = ft_strjoin(temp, buf);
		del_buf(buf);
	}
	fd_table[fd] = temp;
	printf("fd : %s\n", fd_table[fd]);
	return get_one_line(fd_table[fd]);
}

int main()
{
	char	*temp;
	int fd = open("./test.txt", O_RDONLY);
	if (fd > 0)
	{
		temp = get_next_line(fd);
		temp = get_next_line(fd);
		temp = get_next_line(fd);
		temp = get_next_line(fd);
		temp = get_next_line(fd);
	}
	close(fd);
	free(temp);
	return 0;
}
