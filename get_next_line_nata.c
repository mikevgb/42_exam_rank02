#include <stdio.h>

size_t 	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int 	i, j;
	char 	*str;

	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int 	get_next_line(int fd, char **line)
{
	int 	n_bytes;
	char 	*buff;
	
	if (!line || !(buff = (char*)malloc(2)) || !(*line = (char*)malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while ((n_bytes = read(fd, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (buff[0] == '\n' || buff[0] == '\0')
			break;
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	return (n_bytes);
}