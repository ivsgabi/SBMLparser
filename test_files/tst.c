/*
** EPITECH PROJECT, 2023
** tst
** File description:
** 
*/

#include <stdio.h>
#include <string.h>

char* getMotPrecedent(char* chaine) {
    char* motPrecedent = NULL;
    int longueurChaine = strlen(chaine);
    
    for (int i = 0; i < longueurChaine; i++) {
        if (chaine[i] == '=') {
            int debutMot = i - 1;
            
            while (debutMot >= 0 && chaine[debutMot] == ' ') {
                debutMot--;
            }
            
            int finMot = debutMot;
            
            while (debutMot >= 0 && chaine[debutMot] != ' ') {
                debutMot--;
            }
            
            int longueurMot = finMot - debutMot - 1;
            
            if (longueurMot >= 0) {
                motPrecedent = (char*) malloc((longueurMot + 2) * sizeof(char));
                
                if (motPrecedent != NULL) {
                    strncpy(motPrecedent, &chaine[debutMot + 1], longueurMot + 1);
                    motPrecedent[longueurMot + 1] = '\0';
                }
            }
            
            break;
        }
    }
    
    return motPrecedent;
}
