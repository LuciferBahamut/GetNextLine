/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** get next line
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int get_nb_calls(void)
{
    int i = 9;
    i++;
    return (0);
}

void read_and_display_read_line_n(int fd, int n)
{
    char *buffer = malloc(3 + 1);
    int re = read(fd, buffer, 3);

    get_nb_calls();
    for (int i = 0; i < n; i++)
        printf("%c", buffer[i]);
    free (buffer);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (84);
    read_and_display_read_line_n(fd, 3);
    close (fd);
}
