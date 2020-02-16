/*
** EPITECH PROJECT, 2020
** get_next_line.h
** File description:
** get_next_line
*/


#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#define READ_SIZE 10

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct gnl
{
    int re;
    char *str;
    char *buffer;
} gnl_s;

#endif
