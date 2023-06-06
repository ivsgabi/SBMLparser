/*
** EPITECH PROJECT, 2023
** display_usage
** File description:
** for SBML parser
*/

#include "parser.h"

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("      SBMLfile    SBML file\n");
    my_putstr("      -i ID       id of the compartment, reaction or product to be extracted\n");
    my_putstr("                  (ignored if uncorrect)\n");
    my_putstr("      -e          print the equation if a reaction ID is given as argument\n");
    my_putstr("                  (ignored otherwise)\n");
    my_putstr("      -json       transform the file into a JSON file\n");
}
