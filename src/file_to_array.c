/*
** EPITECH PROJECT, 2023
** file_to_array
** File description:
** from file to array functions
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parser.h"

char *open_read_file(char *str)
{
    char *buffer = NULL;
    int fd = 0;
    struct stat size;
    if ((fd = open(str, O_RDONLY)) <= 0)
        return NULL;
    if (stat(str, &size) < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size.st_size + 1));
    if (read(fd, buffer, size.st_size) <= 0)
        return NULL;
    buffer[size.st_size] = '\0';
    close(fd);
    return (buffer);
    free (buffer);
}

int columns(char *str, char separator)
{
    int count = 0;

    for (int i = 0;str[i] != '\0';i++){
        if (str[i] == separator){
            count++;
        }
    }
    if (str[my_strlen(str) - 1] != separator)
        count = count + 1;
    return count;
}

int word_len(char *str, char separator, int l)
{
    int word = 0;

    for (int i = l;str[i] != separator && str[i] != '\0';i++){
        word++;
    }
    return word;
}

char **my_str_to_word_array(char *str, char separator)
{
    int size = columns(str, separator);
    int a = 0;
    int len = 0;
    int new_len = 0;
    char **array = malloc((sizeof(char *)) * (size + 1));

    for (int i = 0;i < size;i++){
        new_len = word_len(str, separator, len);
        len += new_len + 1;
        array[i] = malloc((sizeof(char)) * (new_len + 1));
	for (int k = 0;k < new_len;k++){
            array[i][k] = str[a];
            a++;
        }
        a++;
        array[i][new_len] = '\0';
    }
    array[size] = NULL;
    return array;
}