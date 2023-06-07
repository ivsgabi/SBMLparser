/*
** EPITECH PROJECT, 2023
** list_sorting (tag)
** File description:
** for SBML_parser 
*/

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
