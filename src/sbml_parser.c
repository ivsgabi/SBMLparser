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
    char *args = NULL;
    int nb_lines = 0;
    int j = 0;

    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] == '=') {
            nb_lines++;
        }
    }

    array = malloc(sizeof(char*) * (nb_lines + 1));

    while ((token = strsep(&copy, " \t")) != NULL) {
        if (strstr(token, "=") != NULL) {
            args = strtok(token, "=");
            if (args != NULL) {
                array[j] = strdup(args);
                j++;
            }
        }
    }
    array[j] = NULL;
    return (array);
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
