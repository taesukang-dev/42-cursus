#include "get_next_line.h"

char	*get_one_line(char **s, int nl_pivot)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (nl_pivot + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
	{
		temp[i] = (*s)[i];
		i++;
	}
	temp[i] = '\n';
	temp[i + 1] = '\0';
	i = 0;
	while (i <= nl_pivot)
	{
		(*s)++;
		i++;
	}
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
