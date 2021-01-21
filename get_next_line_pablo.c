#include "get_next_line.h"
​
char	*ft_aux(char *s, char c)
{
	char	*str;
	int		i;
​
	i = 0;
	while(s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
		return(0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return(str);
}
​
int		get_next_line(char **line)
{
	char	*buffer;
	int		flag;
​
	buffer = (char *)malloc(2);
	if (!line || !(*line = malloc(1)) || !buffer)
		return(-1);
	*line[0] = '\0';
	while ((flag = read(0, buffer, 1) > 0))
	{
		if (buffer[0] == '\n')
			break;
		*line = ft_aux(*line, buffer[0]);
	}
	free(buffer);
	return(flag);
}