#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_one_line(char **s, int nl_pivot)
{
	char	*temp;
	char	*new_fd;

	new_fd = ft_strdup(*s + nl_pivot + 1);
	temp = malloc(nl_pivot + 2);
	if (!temp)
	{
		free(new_fd);
		return (NULL);
	}
	ft_strlcpy(temp, *s, nl_pivot + 2);
	free(*s);
	*s = new_fd;

	return (temp);
}

int	ft_find_nl(char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*fd_table[OPEN_MAX] = {0, };
	char		buf[BUFFER_SIZE + 1];
	int			read_len;
	int			nl_pivot;

	while (1)
	{
		nl_pivot = ft_find_nl(fd_table[fd]);
		if (nl_pivot >= 0)
			return (get_one_line(&fd_table[fd], nl_pivot));
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buf[read_len] = '\0';
		fd_table[fd] = ft_strjoin(fd_table[fd], buf);
		if (!fd_table[fd])
			return (NULL);
	}
	return (fd_table[fd]);
}


int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *temp;
	if (fd > 0)
	{
		temp = get_next_line(fd);
		printf("%s", temp);
		temp = get_next_line(fd);
		printf("%s", temp);
		temp = get_next_line(fd);
		printf("%s", temp);
	}
	return 0;
}