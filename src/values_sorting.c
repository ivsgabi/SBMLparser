/*
** EPITECH PROJECT, 2023
** values_sorting
** File description:
** for SBML parser
*/

#include <stddef.h>
#include <string.h>

void swap(char **str1, char **str2) 
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

char **sort_array(char **array) 
{
    if (array == NULL)
        return NULL;
    int count = 0;
    while (array[count] != NULL) {
        count++;
    }

    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < count - 1; i++) {
            if (strcmp(array[i], array[i + 1]) > 0) {
                swap(&array[i], &array[i + 1]);
                sorted = 0;
            }
        }
    }
    return (array);
}
