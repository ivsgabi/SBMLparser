/*
** EPITECH PROJECT, 2023
** list_utils
** File description:
** for SBML parser
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h> // temporary
#include "parser.h"

l_sbml *create_elem(char *tag, char *value)
{
    l_sbml *node = malloc(sizeof(l_sbml));

    if (node == NULL)
        return NULL;
    node->tag = strdup(tag);
    node->value = strdup(value);
    node->next = NULL;
    return (node);
}

bool insert_elem(l_sbml **list, char *tag, char *value)
{
    l_sbml *node = create_elem(tag, value);
    l_sbml *tmp;

    if (node == NULL)
        return false;
    if (*list == NULL) {
        *list = node;
    } else {
        for (tmp = *list; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
    return (true);
}

void my_tag_printer(l_sbml **list)
{
    l_sbml *temp = *list;
    while (temp != NULL) {
        my_putstr(temp->tag);
        my_putchar('\n');
        temp = temp->next;
    }
    my_putchar('\n');
}

void my_value_printer(l_sbml **list)
{
    l_sbml *temp = *list;
    while (temp != NULL) {
        my_putstr(temp->value);
        my_putchar('\n');
        temp = temp->next;
    }
    my_putchar('\n');
}

void free_list(l_sbml **points)
{
    l_sbml *list = *points;
    l_sbml *tmp;
    while (list != NULL) {
        tmp = list;
	list = list->next;
        free(tmp);
    } 
    *points = NULL;
}
