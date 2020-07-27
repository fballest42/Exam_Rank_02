#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int     i;
    i = 0;
    while (str[i] != 0)
        i++;
    return(i);
}
char    *ft_strdup(char *str)
{
    int     i = 0;
    char    *dest;
    if (!(dest = malloc(ft_strlen(str) + 1)))
        return(0);
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}
char    *ft_strjoin(char *str, char *c)
{
    int     i;
    char    *dest;
    if(!(dest = malloc(ft_strlen(str) + 2)))
        return(0);
    i = 0;
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = c[0];
    dest[i + 1] = '\0';
    free(str);
    return(dest);
}
int     get_next_line(char **line)
{
    char    *buf;
    int     ret;
    buf = malloc(2);

    if (line == NULL || !(*line = ft_strdup("")))
        return(-1);
    while ((ret = read(0, buf, 1)) > 0)
    {
        if (buf[0] == '\n')
            break ;
        *line = ft_strjoin(*line, buf);
    }
    free(buf);
    return(ret);
}
