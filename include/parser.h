/*
** EPITECH PROJECT, 2023
** header
** File description:
** for SBML parser
*/

#ifndef _PARSER_H_
    #define _PARSER_H_

#include <stdbool.h>

typedef struct l_sbml {
    char *tag;
    char *value;
    struct l_sbml* next;
} l_sbml;

typedef struct sbml_t {
    char *compartment_id;
    char *compartment_name; 
    char *model_name; 
    char *model_id; 
    char *reaction_name;
    char *reaction_id;
    char *reaction_reversible;
    char *sbml_level;
    char *sbml_version;
    char *sbml_xmlns;
    char *species_compartement;
    char *species_id;
    char *species_name;
    char *speciesReference_species;
    char *speciesReference_stoichiometry;
} sbml_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

char *open_read_file(char *str);
int rows_counter(char *str);
int cols_counter(char *str);
char **my_str_to_word_array(char *str, char separator);

void display_usage(void);

l_sbml *create_elem(char *tag, char *value);
bool insert_elem(l_sbml **list, char *tag, char *value);
void my_tag_printer(l_sbml **list);
void my_value_printer(l_sbml **list);

int in_list_condition(l_sbml **list, char **array);
int sbml_parser_base(l_sbml **list);
char **sort_array(char **array);

#endif