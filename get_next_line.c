/*
** EPITECH PROJECT, 2020
** getnextline
** File description:
** getnextline
*/

#include "my.h"
#include "get_next_line.h"

static char *temp_stat(char *str, int i)
{
    char *temp = malloc((READ_SIZE + 1) * sizeof(char));

    i++;
    for (int j = 0; str[i] != '\0'; i++, j++)
        temp[j] = str[i];
    return (temp);
}

char *s_fill(char *buffer, char *str)
{
    int i = 0;

    buffer[READ_SIZE + 1] = '\0';
    while (buffer[i] != '\0')
        i++;
    if (buffer[i - 1] == '\n')
        i--;
    str = malloc((READ_SIZE + 1) * sizeof(char));
    for (int j = 0; j != i; j++)
        str[j] = buffer[j];
    free(buffer);
    return (str);
}

char *fs_fill(char *str, char *temp)
{
    char *f_str = malloc((READ_SIZE + 1) * sizeof(char));
    int i = 0;

    if (str == NULL)
        return (temp);
    else {
        for (int j = 0; temp[j] != '\0'; j++, i++)
            f_str[i] = temp[j];
        i++;
        for (int j = 0; str[j] != '\n'; j++, i++)
            f_str[i] = str[j];
        free(temp);
    }
    return (str);
}

char *new_str(char *str)
{
    char *f_str;
    int nb = 0;
    int nb2 = 0;

    for (int i = 0; str[i] != '\0'; i++, nb++);
    for (int j = 0; str[j] != '\n'; j++, nb2++);
    f_str = malloc((READ_SIZE + 1) * sizeof(char));
    for (int i = 0; str[i] != '\n'; i++)
        f_str[i] = str[i];
    free(str);
    return(f_str);
}

char *get_next_line(int fd)
{
    char *buffer = malloc((READ_SIZE + 1) * sizeof(char));
    char *str = 0;
    int re = read(fd, buffer, READ_SIZE);
    static char *temp = 0;

    if (temp != 0) {
        str = fs_fill(str, temp);
        temp = 0;
    }
    else {
        if (fd == -1 || re <= 0)
            return (NULL);
        str = s_fill(buffer, str);
        for (int i = 0; str[i]; i++)
            if (str[i] == '\n') {
                temp = temp_stat(str, i);
                str = new_str(str);
            }
    }
    return (str);
}
