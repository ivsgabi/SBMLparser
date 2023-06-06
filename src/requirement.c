/*
** EPITECH PROJECT, 2023
** requirement fct
** File description:
** for SBML parser
*/

#include <stddef.h>

int rows_counter(char *str)
{
    int i = 0;
    int res = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n' || str[i] == '\0') {
            res++;
        } i++;
    } return (res);
}

int cols_counter(char const *str)
{
    int count = 0;
    while (str[count] != '\n') {
        count++;
    } return (count);
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int nb_cols = cols_counter(str);
    int nb_rows = rows_counter(str);
    int i = 0;
    int j = 0;
    int x = 0;
    int res = 0;
    char **board = malloc(sizeof(char *) * (nb_rows + 1));
    
    if (board == NULL)
        return NULL;
    
    for (i = 0 ; i < nb_rows; i++) {
	nb_cols = nb_cols + res;  
        board[i] = malloc(sizeof(char) * (nb_cols + 1));
	for (j = 0; j < nb_cols; j++) {
            board[i][j] = str[x];
            x++;
	}
        x++;
        board[i][nb_cols] = '\0';
        res = res + nb_cols + 1;
    }
    board[nb_rows] = NULL;
    return (board);
}
