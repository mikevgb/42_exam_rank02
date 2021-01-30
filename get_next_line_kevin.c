#include <unistd.h>
#include <stdlib.h>

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

int get_next_line (char **line)
{
    char buffer;
    int flag;

    if(!line  || !(*line = malloc (1)))
        return (-1);
        *line [0] = '\0';
        while ((flag = read(0, &buffer, 1) > 0))
        {
            *line = ft_aux (*line, buffer);
            if (buffer == '\n')
                break;
            // *line = ft_aux (*line, buffer); //without main remove the top one and uncomment this
        }
        return (flag);
}

int main (int argc, char ** argv)
{
    char *line;
   while (get_next_line(&line))
   {
        printf("%s", line);
   }
        
        
    
    return (0);
}