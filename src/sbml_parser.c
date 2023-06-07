/*
** EPITECH PROJECT, 2023
** sbml_parser
** File description:
** for SBML parser project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "parser.h"

void alpha_sorting(l_sbml* list) 
{
    int swapped;
    l_sbml *lptr = NULL;
    l_sbml *ptr1;

    if (list == NULL)
        return;

    swapped = 1;
    while (swapped != 0) {
        swapped = 0;
        ptr1 = list;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->tag, ptr1->next->tag) > 0) {
                char* temp = ptr1->tag;
                ptr1->tag = ptr1->next->tag;
                ptr1->next->tag = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

int sort_tag_nodes(l_sbml **list) 
{
    if (*list == NULL || (*list)->next == NULL) {
        return (84);
    }

    l_sbml *sorted_list = NULL;
    l_sbml *current = *list;
    l_sbml *next = NULL;

    while (current != NULL) {
        next = current->next;
        if (sorted_list == NULL || strcmp(current->tag, sorted_list->tag) < 0) {
            current->next = sorted_list;
            sorted_list = current;
        } else {
            l_sbml *temp = sorted_list;
            while (temp->next != NULL && strcmp(current->tag, temp->next->tag) >= 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *list = sorted_list;
    return (0);
}

char** value_parsing(char* value)
{
    char** array = NULL;
    char* copy = strdup(value);
    char* token = NULL;
    int count = 0;

    while ((token = strsep(&copy, " \t")) != NULL) {
        if (strstr(token, "=") != NULL) {
            char* attr = strtok(token, "=");
            if (attr != NULL) {
                array = (char**)realloc(array, sizeof(char*) * (count + 1));
                array[count] = strdup(attr);
                count++;
            }
        }
    }
    array = (char**)realloc(array, sizeof(char*) * (count + 1));
    array[count] = NULL;
    free(copy);
    return (array);
}


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
    return array;
}

int sbml_parser_base(l_sbml **list)
{
    sort_tag_nodes(list);
    l_sbml *temp = *list;
    char **sorted_attributes = NULL;
    

    while (temp != NULL) {
        printf("%s\n", temp->tag);
        sorted_attributes = value_parsing(temp->value);
        sorted_attributes = sort_array(sorted_attributes);
        if (sorted_attributes == NULL)
            return (84);
        for (int i = 0; sorted_attributes[i]; i++) {
            printf("--->%s\n", sorted_attributes[i]);
        }
        temp = temp->next;
    }
    return 0;
}
