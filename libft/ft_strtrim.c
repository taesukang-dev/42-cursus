#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	buf_len;
	char	*buf;

	if (!set || !s1)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	while((9 <= s1[i] && s1[i] <= 13) || s1[i] == ' ')
		i++;
	while((9 <= s1[s1_len] && s1[s1_len] <= 13) || s1[s1_len] == ' ')
		s1_len--;
	buf = calloc(s1_len - i + 1, sizeof(char));
	buf_len = 0;
	while(i < s1_len)
	{
		j = 0;
		if (s1[i] == set[j])
		{
			while(s1[i + j] == set[j])
			{
				j++;
				if (set[j] == '\0')
				{
					i += j;
				}
			}
		}
		buf[buf_len] = s1[i];
		buf_len++;
		i++;	
	}
	buf[buf_len] = '\0';
	return buf;
}

int main()
{
	char *temp = ft_strtrim("asdasd", "d");
	printf("%s", temp);
}
