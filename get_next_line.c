/*
** EPITECH PROJECT, 2020
** getnextline
** File description:
** getnextline
*/

#include "my.h"
#include "get_next_line.h"

char *s_mlc(char *buffer, char *str)
{
    int i = 0;

    while (buffer[i] != '\n')// || buffer[i] != '\0')
        i++;
    str = malloc(i + 1 * sizeof(char));
    for (int j = 0; j != i; j++)
        str[j] = buffer[j];
    return (str);
}

char *get_next_line(int fd)
{
    char *buffer = malloc(READ_SIZE + 1 * sizeof(char));
    char *str;

    buffer[READ_SIZE + 1] = '\0';
    read(fd, buffer, READ_SIZE);
    str = s_mlc(buffer, str);
    free(buffer);
    return (str);
}

/*int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *s = get_next_line(fd);

    while (s) {
        my_putstr(s);
        my_putchar('\n');
        free(s);
        s = get_next_line(fd);
    }
    close(fd);
    return (0);
    }*/
