/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:19:36 by tkang             #+#    #+#             */
/*   Updated: 2022/04/09 17:20:26 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_nl(char *s)
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

static char	*ft_last_one(char **s)
{
	char	*temp;

	temp = gnl_strdup(*s);
	if (!temp || gnl_strlen(temp) == 0)
	{
		free(*s);
		free(temp);
		*s = NULL;
		return (NULL);
	}
	free(*s);
	*s = NULL;
	return (temp);
}

static char	*get_one_line(char **s, int nl_pivot)
{
	char	*temp;
	char	*new_fd;

	new_fd = gnl_strdup(*s + nl_pivot + 1);
	temp = (char *)malloc(sizeof(char) * nl_pivot + 2);
	if (!temp)
	{
		free(new_fd);
		return (NULL);
	}
	gnl_strlcpy(temp, *s, nl_pivot + 2);
	free(*s);
	*s = new_fd;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*fd_table[OPEN_MAX] = {0, };
	char		buf[BUFFER_SIZE + 1];
	int			read_len;
	int			nl_pivot;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		nl_pivot = ft_find_nl(fd_table[fd]);
		if (nl_pivot >= 0)
			return (get_one_line(&fd_table[fd], nl_pivot));
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buf[read_len] = '\0';
		fd_table[fd] = gnl_strjoin(fd_table[fd], buf);
		if (!fd_table[fd])
			return (NULL);
	}
	return (ft_last_one(&fd_table[fd]));
}
