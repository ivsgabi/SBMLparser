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


int sbml_parser_base(l_sbml **list)
{
    sort_tag_nodes(list);
    
    return (0);
}

//void bubble_sort(char* arr[], int n) 
//{
//    char* temp;
//    int i = 0;,
//    int j = 0;
//
//    for (i = 0; i < n-1; i++) {
//        for (j = 0; j < n-i-1; j++) {
//            if (strcmp(arr[j], arr[j+1]) > 0) {
//                temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//        }
//    }
//}