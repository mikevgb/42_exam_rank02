#include "get_next_line.h"

char    *ft_aux(char *s, int c)
{
    char *str;
    int i;

    i = 0;
    while (s[i])
        i++;
    if (!(str  = (char *) malloc (2 + i)))
       return (0);
    i = -1;
    while (s[++i])
        str[i] = s[i];
    str[i] = c;
    str[i + 1] = '\0';
    free(s);
    return(str);
}

int     get_next_line (char **line)
{
    char buffer;
    int flag = 0;

    if(!line  || !(*line = malloc (1)))
        return (-1);
    *line [0] = '\0';
    while ((flag = read(0, &buffer, 1)) > 0)
    {
        if (buffer == '\n')
        break;
        *line = ft_aux (*line, buffer);
    }
    return (flag);
}
