/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** for SBML parser
*/

#include <stddef.h>
#include "parser.h"

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int len_str = my_strlen(str);
    int len_to_find = my_strlen(to_find);

    if (len_to_find == 0) {
	return (NULL);
    }
    for (int i = 0; i <= len_str - len_to_find; i++) {
	for (j = 0; j < len_to_find; j++) {
            if (str[i + j] != to_find[j]) {
		break;
            }
	}
        if (j == len_to_find) {
            return (str + i);
	}
    }
    return (NULL);
}
