#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef enum{
     E1,  B1,  E7,  O7,  E3,
     B3,  O3,  C3,  E2,  B2,
     O2,  C2,  O1,  C1, E12,
    B12, O12, C12, E11, B11,
    O11, C11, E10, B10, O10,
    C10,  B7,  C7,  E6,  B6,
     O6,  C6,  E5,  B5,  O5,
     C5,  E4,  B4,  O4,  C4,
     ERROR
} Card;

typedef enum{ESPADA, BASTO, ORO, COPA} Palo;

typedef struct Carta_s{
    Palo palo;
    int numero;
    int valor;
    int valorEnvido;
} Carta;

typedef struct Mano_s{
    Carta carta1;
    Carta carta2;
    Carta carta3;
    char tanto;
} Mano;

const static struct {
    Card        val;
    const char *str;
} conversion [] = {{E1,"E1"},{B1,"B1"},{E7,"E7"},{O7,"O7"},{E3,"E3"},{B3,"B3"},{O3,"O3"},{C3,"C3"},{E2,"E2"},{B2,"B2"},{O2,"O2"},{C2,"C2"},{O1,"O1"},{C1,"C1"},{E12,"E12"},{B12,"B12"},{O12,"O12"},{C12,"C12"},{E11,"E11"},{B11,"B11"},{O11,"O11"},{C11,"C11"},{E10,"E10"},{B10,"B10"},{O10,"O10"},{C10,"C10"},{B7,"B7"},{C7,"C7"},{E6,"E6"},{B6,"B6"},{O6,"O6"},{C6,"C6"},{E5,"E5"},{B5,"B5"},{O5,"O5"},{C5,"C5"},{E4,"E4"},{B4,"B4"},{O4,"O4"},{C4,"C4"}};

#endif // MAIN_H_INCLUDED
