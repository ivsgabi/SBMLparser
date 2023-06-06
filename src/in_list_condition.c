/*
** EPITECH PROJECT, 2023
** fill_list
** File description:
** for SBML parser
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "parser.h"

bool is_equal(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '=') {
            return (true);
        }
    }
    return (false);
}

int tag_length(char *line)
{
    int len = 0;
    for (; line[len] != ' '; len++);
    return (len);
}

char *create_tag(char *line)
{
    int tag_size = tag_length(line);
    char *tag = malloc(sizeof(char) * (tag_size + 1));
    int i = 1;
    int j = 0;

    for (; line[i] != ' '; i++) {
        tag[j] = line[i];
        j++;
    }
    tag[j] = '\0';
    return (tag);
}

char *create_value(char *line)
{
    int value_size = my_strlen(line) - tag_length(line);
    char *value = malloc(sizeof(char) * (value_size + 1));
    int i = 0;
    int j = 0;

    for (; line[i] != ' '; i++);
    i++;
    for (; line[i] != '\0'; i++) {
        value[j] = line[i];
        j++;
    }
    value[j] = '\0';
    return (value);
}

bool is_tag_double(l_sbml* list, char* tag) 
{
    l_sbml* current = list;
    
    while (current != NULL) {
        if (strcmp(current->tag, tag) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int in_list_condition(l_sbml** list, char** array) 
{
    char* tag = NULL;
    char* value = NULL;

    for (int i = 1; array[i]; i++) {
        if (array[i][0] == '<' && is_equal(array[i]) == true) {
            tag = create_tag(array[i]);
            value = create_value(array[i]);

            if (is_tag_double(*list, tag) == false) {
                insert_elem(list, tag, value);
            }
        }
    }
    return 0;
}
