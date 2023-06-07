/*
** EPITECH PROJECT, 2023
** main
** File description:
** for SBML parser
*/

#include <string.h>
#include <stddef.h>
#include "parser.h"

int main(int argc, char **argv)
{
    l_sbml *list = NULL;

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        display_usage();
        return (0);
    }

    char *buffer = open_read_file(argv[1]);
    if (buffer == NULL)
        return (84);
    char **array = my_str_to_word_array(buffer, '\n');
    if (array == NULL)
        return (84);

    in_list_condition(&list, array);
    //my_tag_printer(&list);
    //my_value_printer(&list);
    sbml_parser_base(&list);
    return (0);
}
