#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO hacer array de manos dependiendo de cant de jugadores con orden del 1 al X para saber quien es mano y quien pie
//se puede hacer un struct Juego
//char jugadores;
//bool flor;

const static Carta mazo[] = {{ESPADA,1,1,1},{BASTO,1,2,1},{ESPADA,7,3,7},{ORO,7,4,7},{ESPADA,3,5,3},{BASTO,3,5,3},{ORO,3,5,3},{COPA,3,5,3},{ESPADA,2,6,2},{BASTO,2,6,2},{ORO,2,6,2},{COPA,2,6,2},{ORO,1,7,1},{COPA,1,7,1},{ESPADA,12,8,0},{BASTO,12,8,0},{ORO,12,8,0},{COPA,12,8,0},{ESPADA,11,9,0},{BASTO,11,9,0},{ORO,11,9,0},{COPA,11,9,0},{ESPADA,10,10,0},{BASTO,10,10,0},{ORO,10,10,0},{COPA,10,10,0},{BASTO,7,11,7},{COPA,7,11,7},{ESPADA,6,12,6},{BASTO,6,12,6},{ORO,6,12,6},{COPA,6,12,6},{ESPADA,5,13,5},{BASTO,5,13,5},{ORO,5,13,5},{COPA,5,13,5},{ESPADA,4,14,4},{BASTO,4,14,4},{ORO,4,14,4},{COPA,4,14,4}};
Mano miMano;

Carta carta(Card x){
    return mazo[x];
}

void setMano(Mano * m, Card c1, Card c2, Card c3){
    (*m).carta1 = mazo[c1];
    (*m).carta1 = mazo[c2];
    (*m).carta3 = mazo[c3];
    calcularTanto(m);
}

void calcularTanto(Mano * m){
    (*m).tanto = 20;
    if((*m).carta1.palo == (*m).carta2.palo){
        (*m).tanto += ((*m).carta1.valorEnvido + (*m).carta2.valorEnvido);
    } else if((*m).carta1.palo == (*m).carta3.palo){
        (*m).tanto += ((*m).carta1.valorEnvido + (*m).carta3.valorEnvido);
    } else if((*m).carta2.palo == (*m).carta3.palo){
        (*m).tanto += ((*m).carta2.valorEnvido + (*m).carta3.valorEnvido);
    } else {
        (*m).tanto -= 20;
        if((*m).carta1.valorEnvido > (*m).tanto) (*m).tanto = (*m).carta1.valorEnvido;
        if((*m).carta2.valorEnvido > (*m).tanto) (*m).tanto = (*m).carta2.valorEnvido;
        if((*m).carta3.valorEnvido > (*m).tanto) (*m).tanto = (*m).carta3.valorEnvido;
    }
}

Card str2card(const char *str){
    for(int j = 0;  j < sizeof (conversion) / sizeof (conversion[0]);  j++) if(!strcmp(str, conversion[j].str)) return conversion[j].val;
    return ERROR;
}

char *carta2str(Carta c){
    char str[3], x;
    switch(c.palo){
        case ESPADA:
            x = 'E';
            break;
        case BASTO:
            x = 'B';
            break;
        case ORO:
            x = 'O';
            break;
        case COPA:
            x = 'C';
            break;
    }
    sprintf(str, "%c", x);
    return str;
}

void obtenerMano(){
    char c[3][4];
    printf("Ingrese las cartas de su mano usando\n(E - B - O - C) como el palo y el numero.\n(Por ejemplo, E7 es el 7 de espada)\n");
    for(int i = 1; i <=3; i++){
        printf("\nIngrese carta %d: ", i);
        fgets(c[i], 4, stdin);
    }
    setMano(&miMano, str2card(c[1]), str2card(c[2]), str2card(c[3]));
    printf("\nMano: %s %s %s", carta2str(miMano.carta1), carta2str(miMano.carta2), carta2str(miMano.carta3));
}

int main(){
    obtenerMano();
    return 0;
}
